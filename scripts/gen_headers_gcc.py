from pathlib import Path
from xml.dom import minidom, Node
import glob
import re

input_path = "headers/"
output_path = "platform/gcc/"

def innerText(xml):
    t = ""
    for node in xml.childNodes:
        if node.nodeType == Node.TEXT_NODE:
            t += node.nodeValue
        elif node.nodeType == Node.ELEMENT_NODE:
            t += innerText(node)
    return t

def comment_to_lines(xml):
    return [x.strip() for x in innerText(xml).splitlines()]

def print_long_comment(c, f):
    if len(c) == 0:
        return
    if len(c) == 1:
        f.write(f"/* {c[0]} */\n")
        return
    for i in range(len(c)):
        f.write("\n * " if i > 0 else "/* ")
        f.write(c[i])
    f.write("\n*/\n")

def convert_type(xml):
    t = xml.attributes["type"].nodeValue
    is_far = "register" in xml.attributes and (":" in xml.attributes["register"].nodeValue)
    is_far = is_far or ("far" in xml.attributes)
    if t == "s8":
        return "int8_t"
    if t == "s16":
        return "int16_t"
    if t == "s32":
        return "int32_t"
    if t == "u8":
        return "uint8_t"
    if t == "u16":
        return "uint16_t"
    if t == "u32":
        return "uint32_t"
    if t == "void*" or t == "char*" or t == "intvector_t*" or t == "ownerinfo_t*" or t == "datetime_t*":
        is_const = "const" in xml.attributes
        return ("const " if is_const else "") + (t.replace("*", " __far*") if is_far else t)
    print(f"Warning: Unknown type {t}")
    return "void*"

constraint_map = {
    "ah": "Rah",
    "al": "Ral",
    "cl": "Rcl",
    "bp": "Rbp",
    "ds": "Rds",
    "ax": "a",
    "bx": "b",
    "cx": "c",
    "dx": "d",
    "si": "S",
    "di": "D",
    "dx:ax": "A",
    "es": "e"
}

def convert_return_constraint(xml):
    r = xml.attributes["register"].nodeValue if xml is not None else "ax"
    if r == "dx:ax":
        return "A"
    else:
        return "a"

def can_use_inline_implementation(f):
    if "int" not in f.attributes:
        # Not an interrupt wrapper
        return False

    return_node = None

    for node in f.childNodes:
        if node.nodeType != Node.ELEMENT_NODE:
            continue
        if node.nodeName == "return":
            if return_node is None:
                return_node = node
            else:
                # Uses pointers to output arguments
                return False
        elif node.nodeName == "argument":
            if "__far" in convert_type(node):
                # Uses far pointers
                return False
    
    return True

# dict["bl"] + dict["bh"] => dict["bx"], etc.
def combine_registers(register_map, low, high, joined):
    if low in register_map and high in register_map:
        register_map[joined] = f"(({register_map[high]} << 8) | {register_map[low]})"
        del register_map[low]
        del register_map[high]
    elif low in register_map:
        register_map[joined] = register_map[low]
        del register_map[low]

def write_function(f, output_file, include_implementation=False):
    return_node = None
    constant_values = {}
    argument_nodes = []

    for node in f.childNodes:
        if node.nodeType != Node.ELEMENT_NODE:
            continue
        if node.nodeName == "return" and return_node is None:
            return_node = node
        elif node.nodeName == "argument" or node.nodeName == "return":
            argument_nodes.append(node)
        elif node.nodeName == "constant":
            constant_values[node.attributes["register"].nodeValue] = node.attributes["value"].nodeValue

    # Write function definition
    output_file.write(convert_type(return_node) if return_node is not None else "void")
    output_file.write(" " + f.attributes["name"].nodeValue + "(")

    ## Arguments
    if len(argument_nodes) > 0:
        for i in range(len(argument_nodes)):
            if i > 0:
                output_file.write(", ")
            argument_node = argument_nodes[i]
            output_file.write(convert_type(argument_node))
            if argument_node.nodeName == "return":
                output_file.write(" __far*")
            output_file.write(" " + argument_node.attributes["name"].nodeValue)
    else:
        output_file.write("void")
    output_file.write(")")

    if include_implementation:
        # print(f"{f.attributes["name"].nodeValue}...")
        output_file.write(" {\n")

        # Generate temporary values
        result_type = "uint16_t"
        if return_node is not None and "32" in return_node.attributes["type"].nodeValue:
            result_type = "uint32_t"
        output_file.write(f"\t{result_type} result;\n")
        for node in argument_nodes:
            if node.nodeName == "return":
                name = node.attributes["name"].nodeValue
                output_file.write(f"\t{convert_type(node)} _{name};\n")

        # Generate ASM block
        irq = f.attributes["int"].nodeValue
        output_file.write("\t__asm volatile (\n")
        output_file.write(f"\t\t\"int ${irq}\"\n")

        ## Outputs
        output_file.write(f"\t\t: \"={convert_return_constraint(return_node)}\" (result)")
        for node in argument_nodes:
            if node.nodeName == "return":
                cons = constraint_map[node.attributes["register"].nodeValue]
                name = node.attributes["name"].nodeValue
                output_file.write(f", \"={cons}\" (_{name})")
        output_file.write("\n")

        ## Inputs
        output_file.write("\t\t:")
        inputs = []
        encountered_ds = False
        register_map = {}
        for node in argument_nodes:
            if node.nodeName == "argument":
                cons = node.attributes["register"].nodeValue
                name = node.attributes["name"].nodeValue
                if cons.startswith("ds:"):
                    # Special case - ds:dx, etc.
                    # If multiple ds: arguments, use the first ds
                    if not encountered_ds:
                        inputs.append(f"\"Rds\" (FP_SEG({name}))")
                        encountered_ds = True
                    cons = constraint_map[cons[3:]]
                    inputs.append(f"\"{cons}\" (FP_OFF({name}))")
                elif cons == "al" and "ah" in constant_values:
                    # Special case - AL argument mixed with AH constant
                    ah_constant = constant_values["ah"]
                    del constant_values["ah"]
                    inputs.append(f"\"a\" ((uint16_t) ((({ah_constant}) << 8) | ({name} & 0xFF)))")
                else:
                    register_map[cons] = name
        combine_registers(register_map, "bl", "bh", "bx")
        combine_registers(register_map, "cl", "ch", "cx")
        combine_registers(register_map, "dl", "dh", "dx")
        for cons in register_map:
            name = register_map[cons]
            cons = constraint_map[cons]
            inputs.append(f"\"{cons}\" ({name})")
        for cons in constant_values:
            cast = "uint8_t" if (cons.endswith("l") or cons.endswith("h")) else "uint16_t"
            name = constant_values[cons]
            cons = constraint_map[cons]
            inputs.append(f"\"{cons}\" (({cast}) {name})")
        for i in range(len(inputs)):
            if i > 0:
                output_file.write(",")
            output_file.write(f" {inputs[i]}")
        output_file.write("\n")

        ## Clobbers
        output_file.write("\t\t: \"cc\", \"memory\"\n")
        
        output_file.write("\t);\n")

        # Generate return values
        for node in argument_nodes:
            if node.nodeName == "return":
                name = node.attributes["name"].nodeValue
                output_file.write(f"\tif ({name}) *{name} = _{name};\n")
        if return_node is not None:
            output_file.write("\treturn result;\n")

        output_file.write("}\n")
    else:
        output_file.write(";\n")

def write_header(filename, xml, output_file):
    header_define = "__LIBWW_" + re.sub("[^0-9a-zA-Z]", "_", filename).upper() + "__"
    output_file.write(f"#include <sys/types.h>\n\n")
    output_file.write(f"#ifndef {header_define}\n#define {header_define}\n\n")
    output_file.write(f"/* Begin auto-generated section */\n\n")
    for node in xml.documentElement.childNodes:
        # Preserve in-XML newlines
        if node.nodeType == Node.TEXT_NODE:
            output_file.write(node.nodeValue.replace("\n", "", 1).replace(" ", "").replace("\t", ""))
            continue
        if node.nodeType != Node.ELEMENT_NODE:
            continue
        if node.nodeName == "comment":
            print_long_comment(comment_to_lines(node), output_file)
        elif node.nodeName == "define":
            print_long_comment(comment_to_lines(node), output_file)
            output_file.write(f"#define {node.attributes['name'].nodeValue} {node.attributes['value'].nodeValue}\n")
        elif node.nodeName == "function":
            # TODO: Output <comment> tag
            # Generate function declaration
            if can_use_inline_implementation(node):
                output_file.write("static inline ")
                write_function(node, output_file, include_implementation=True)
            else:
                write_function(node, output_file, include_implementation=False)
            output_file.write("\n")

            # Generate function implementation (in separate .c file)
            if "int" in node.attributes:
                c_output_fn = Path(output_path) / "src" / "auto" / (node.attributes["name"].nodeValue + ".c")
                c_output_fn.parent.mkdir(parents=True, exist_ok=True)
                with open(str(c_output_fn), "w") as cf:
                    cf.write(f"#include <sys/types.h>\n\n")
                    write_function(node, cf, include_implementation=True)
        else:
            print(f"Warning: Unknown element {node.nodeName}")
    output_file.write(f"/* End auto-generated section */\n\n")
    output_file.write(f"\n#endif /* {header_define} */\n")

for fn in glob.glob("**/*.xml", root_dir=input_path, recursive=True):
    input_fn = Path(input_path) / fn
    output_fn = Path(output_path) / "include/" / fn.replace(".xml", ".h")
    print(f"Transforming {input_fn} -> {output_fn}")
    input_xml = minidom.parse(str(input_fn))    
    output_fn.parent.mkdir(parents=True, exist_ok=True)
    with open(str(output_fn), "w") as f:
        write_header(fn.replace(".xml", ".h"), input_xml, f)
