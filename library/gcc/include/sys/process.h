#include <sys/types.h>
#include <sys/indirect.h>

#ifndef __LIBWW_SYS_PROCESS_H__
#define __LIBWW_SYS_PROCESS_H__

/* Begin auto-generated section */

#define E_PROC_SUCCESS 0
#define E_PROC_CANTLOAD 0xFFFF

#define S_PCB_NOT_USED 0
#define S_PCB_LOAD 1
#define S_PCB_RUN 2
#define S_PCB_SUSPEND 3

#define MAXPROCESSES 3
/* End auto-generated section */

/**
 * Process control block
 */
typedef struct {
	/**
	 * Compiler ID used to build this binary.
	 *
	 * Known IDs:
	 *
	 * LCC: LSI-C
	 * TCC: Turbo C
	 * DMC: Digital Mars C
	 * GCC: gcc-ia16
	 */
	char _id[4];

	uint8_t todo_1[8];

	/**
	 * Pointer to IlibIL library.
	 */
	IlibIL __far* _ilib;

	/**
	 * Pointer to ProcIL library.
	 */
	ProcIL __far* _proc;

	/**
	 * Pointer to the current working directory's file system.
	 */
	fent_t __far* _cwfs;

	/**
	 * Current working directory.
	 */
	char _currentdir[64];

	/**
	 * Pointer to argv[] structure.
	 */
	char **_argv;

	/**
	 * Pointer to the file's resource area in ROM.
	 */
	void __far* _resource;

	/**
	 * Pointer to the first free byte of heap in SRAM.
	 */
	void *_heap;
} ProcContext;

#if __STDC_VERSION__ > 201112L
_Static_assert(sizeof(ProcContext) == 96, "Invalid ProcContext size!");
#endif

/**
 * Instance of process control block for current process
 */
#define _pc ((ProcContext*) 0x0000)

/**
 * IlibIL library for current process
 */
#define ilibIL (_pc->_ilib)

/**
 * ProcIL library for current process
 */
#define procIL (_pc->_proc)

/**
 * Current working directory's file system for current process
 */
#define cwfs (_pc->_cwfs)

/**
 * Current working directory for current process
 */
#define currentdir (_pc->_currentdir)

#endif /* __LIBWW_SYS_PROCESS_H__ */
