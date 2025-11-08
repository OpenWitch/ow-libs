#include <sys/types.h>
#include <sys/filesys.h>
#include <wonderful.h>

#ifndef __LIBWW_SYS_INDIRECT_H__
#define __LIBWW_SYS_INDIRECT_H__

#define IL_FUNCTION __attribute__((cdecl)) far

typedef struct {
	const char __far *className;
	const char __far *name;
	const char __far *version;
	const char __far *description;
	const char __far* __far* depends;
} ILinfo;

#define ilinfo_get_className(info) MK_FP(FP_SEG((info)), FP_OFF((info)->className))
#define ilinfo_get_name(info) MK_FP(FP_SEG((info)), FP_OFF((info)->name))
#define ilinfo_get_version(info) MK_FP(FP_SEG((info)), FP_OFF((info)->version))
#define ilinfo_get_description(info) MK_FP(FP_SEG((info)), FP_OFF((info)->description))

typedef struct {
	uint32_t todo_1;

	/**
	 * Number of methods, including get_info(...).
	 */
	int n_methods;

	/**
	 * Retrieve the ILinfo struct of a given library.
	 */
	IL_FUNCTION ILinfo __far *(*_get_info)(void) __far;
} IL;
_Static_assert(sizeof(IL) == 10, "Invalid IL size");

typedef struct {
	IL super;

	/**
	 * Load the specified IL from /rom0 or /kern.
	 * The IL header is copied to the provided buffer with addresses
	 * appropriately relocated to match the IL's location in ROM.
	 *
	 * @param name The name of the IL to load.
	 * @param buffer The buffer to store the relocated IL header in.
	 */
	IL_FUNCTION int (*_open)(const char __far *name, IL __far *buffer);

	/**
	 * Load the specified IL from /kern only (system ILs only).
	 * The IL header is copied to the provided buffer with addresses
	 * appropriately relocated to match the IL's location in ROM.
	 *
	 * @param name The name of the IL to load.
	 * @param buffer The buffer to store the relocated IL header in.
	 */
	IL_FUNCTION int (*_open_system)(const char __far *name, IL __far *buffer);
} IlibIL;
_Static_assert(sizeof(IlibIL) == 18, "Invalid IlibIL size");

typedef struct _ProcIL {
	IL super;

	/**
	 * Run the load routine of the specified program.
	 */
	IL_FUNCTION void __far (*_load)(const char __far *name);

	/**
	 * Run the specified entrypoint (from load(...)), populating the
	 * argc/argv fields accordingly.
	 */
	IL_FUNCTION int (*_run)(void __far *entrypoint, int argc, const char __far* __far* argv);

	/**
	 * Execute the specified program. Combines load(...) and run(...).
	 */
	IL_FUNCTION int (*_exec)(const char __far *name, int argc, const char __far* __far* argv);

	/**
	 * Exit with a specified error code (uses BIOS interrupt 0x10).
	 */
	IL_FUNCTION void (*_exit)(int code);

	IL_FUNCTION void (*_yield)(void);
	IL_FUNCTION int (*_suspend)(int i);
	IL_FUNCTION void (*_resume)(int i);
	IL_FUNCTION int (*_swap)(int i);
} ProcIL;

typedef struct _FsIL {
	IL super;

	/**
	 * Retrieve a pointer to the file system's entry table.
	 */
	IL_FUNCTION fent_t __far *(*_entries)(FS fs);

	/**
	 * Retrieve the number of entries in the file system.
	 */
	IL_FUNCTION int (*_n_entries)(FS fs);

	/**
	 * Retrieve the entry with a given index from the file system.
	 */
	IL_FUNCTION int (*_getent)(FS fs, int index, fent_t __far *entry);

	/**
	 * Find the entry with a given file name in the file system.
	 */
	IL_FUNCTION int (*_findent)(FS fs, const char __far *filename, fent_t __far *entry);

	/**
	 * Map a given file to memory. Returns a ROM memory pointer, or NULL.
	 */
	IL_FUNCTION void __far *(*_mmap)(FS fs, const char __far *filename);

	IL_FUNCTION int (*_open)(FS fs, const char __far *filename, int mode, int perms);
	IL_FUNCTION int (*_close)(int fd);
	IL_FUNCTION int (*_read)(int fd, char __far *data, int length);
	IL_FUNCTION int (*_write)(int fd, const char __far *data, int length);
	IL_FUNCTION long (*_lseek)(int fd, long offset, int whence);
	IL_FUNCTION int (*_chmod)(FS fs, const char __far *filename, int mode);
	IL_FUNCTION int (*_freeze)(FS fs, const char __far *filename);
	IL_FUNCTION int (*_melt)(FS fs, const char __far *filename);
	IL_FUNCTION int (*_creat)(FS fs, fent_t __far *entry);
	IL_FUNCTION int (*_unlink)(FS fs, const char __far *filename);

	/**
	 * Re-initialize the file system; this removes all files present on the
	 * file system.
	 */
	IL_FUNCTION int (*_newfs)(FS fs);

	/**
	 * Re-arrange file system contents to maximize the amount of free space.
	 *
	 * The FreyaOS file system architecture, due to being based around NOR
	 * flash, does not automatically free space when a file is deleted.
	 */
	IL_FUNCTION int (*_defrag)(FS fs);

	/**
	 * Query the amount of free space.
	 * @return The amount of free space on the file system, in bytes.
	 */
	IL_FUNCTION unsigned long (*_space)(FS fs);
} FsIL;

#endif /* __LIBWW_SYS_INDIRECT_H__ */
