# SPDX-License-Identifier: CC0-1.0
#
# SPDX-FileContributor: Adrian "asie" Siekierka, 2023

WONDERFUL_TOOLCHAIN ?= /opt/wonderful
TARGET ?= wwitch
WF_TARGET_DIR ?= $(WONDERFUL_TOOLCHAIN)/target/$(TARGET)
include $(WF_TARGET_DIR)/makedefs.mk

# Source code paths
# -----------------

INCLUDEDIRS	:= include
SOURCEDIRS	:= src

# Defines passed to all files
# ---------------------------

DEFINES		:=

# Libraries
# ---------

LIBDIRS		:= $(WF_ARCH_LIBDIRS)

# Build artifacts
# ---------------

NAME		:= ww
BUILDDIR	:= build/$(TARGET)
ARCHIVE		:= $(BUILDDIR)/lib$(NAME).a

# Verbose flag
# ------------

ifeq ($(V),1)
_V		:=
else
_V		:= @
endif

# Source files
# ------------

SOURCES_S	:= $(shell find -L $(SOURCEDIRS) -name "*.s")
SOURCES_C	:= $(shell find -L $(SOURCEDIRS) -name "*.c")

# Compiler and linker flags
# -------------------------

WARNFLAGS	:= -Wall

INCLUDEFLAGS	:= $(foreach path,$(INCLUDEDIRS),-I$(path)) \
		   $(foreach path,$(LIBDIRS),-I$(path)/include)

ASFLAGS		+= -x assembler-with-cpp $(DEFINES) $(WF_ARCH_CFLAGS) \
		   $(INCLUDEFLAGS) -ffunction-sections -fdata-sections

CFLAGS		+= -std=gnu11 $(WARNFLAGS) $(DEFINES) $(WF_ARCH_CFLAGS) \
		   $(INCLUDEFLAGS) -ffunction-sections -fdata-sections \
		   -Os -fno-jump-tables -g

# Intermediate build files
# ------------------------

OBJS_SOURCES	:= $(addsuffix .o,$(addprefix $(BUILDDIR)/,$(SOURCES_S))) \
		   $(addsuffix .o,$(addprefix $(BUILDDIR)/,$(SOURCES_C)))

OBJS		:= $(OBJS_SOURCES)

DEPS		:= $(OBJS:.o=.d)

# Targets
# -------

.PHONY: all clean doc install

all: $(ARCHIVE)

$(ARCHIVE): $(OBJS)
	@echo "  AR      $@"
	@$(MKDIR) -p $(@D)
	$(_V)$(AR) rcs $@ $(OBJS)

clean:
	@echo "  CLEAN"
	$(_V)$(RM) $(ARCHIVE) $(BUILDDIR)

doc:
	@echo "  MKDIR    build/doc"
	$(_V)$(MKDIR) -p build/doc
	@echo "  DOXYGEN"
	doxygen

install: all
	@echo "  INSTALL $(ARCHIVE)"
	$(_V)$(MKDIR) -p $(WF_TARGET_DIR)/lib
	$(_V)$(CP) -ar include $(WF_TARGET_DIR)
	$(_V)$(CP) -ar $(ARCHIVE) $(WF_TARGET_DIR)/lib

# Rules
# -----

$(BUILDDIR)/%.s.o : %.s
	@echo "  AS      $<"
	@$(MKDIR) -p $(@D)
	$(_V)$(CC) $(ASFLAGS) -MMD -MP -c -o $@ $<

$(BUILDDIR)/%.c.o : %.c
	@echo "  CC      $<"
	@$(MKDIR) -p $(@D)
	$(_V)$(CC) $(CFLAGS) -MMD -MP -c -o $@ $<

# Include dependency files if they exist
# --------------------------------------

-include $(DEPS)
