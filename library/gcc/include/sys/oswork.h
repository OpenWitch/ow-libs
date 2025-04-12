#include <sys/types.h>
#include <sys/process.h>

#ifndef __LIBWW_SYS_OSWORK_H__
#define __LIBWW_SYS_OSWORK_H__

/* Begin auto-generated section */

#define TMPBUFSZ 128
#define XMODEMBUFSZ TMPBUFSZ
#define MAXFILES 16
#define MAXSTREAMILS MAXFILES

/* File table defines */
#define ROOTFS_NUM_ENTRIES 16
#define RAM0FS_NUM_ENTRIES 64
#define ROM0FS_NUM_ENTRIES 128
/* End auto-generated section */

/**
 * SRAM work area used by FreyaOS.
 */
typedef struct {
	/**
	 * FreyaOS process context
	 */
	ProcContext _ospc;
	uint8_t todo_1[0x6C - 0x60];

	/**
	 * FreyaOS version.
	 *
	 * bit 0-7: patch version
	 * bit 8-11: minor version
	 * bit 12-15: major version
	 */
	uint16_t _os_version;

	uint8_t todo_2[0x2F2 - 0x6E];

	/**
	 * Filesystem entries for the root directory ("/")
	 */
	fent_t _root_fs_entries[ROOTFS_NUM_ENTRIES];

	/**
	 * Filesystem entries for the RAM0 ("/ram0")
	 */
	fent_t _ram0_fs_entries[RAM0FS_NUM_ENTRIES];

	/**
	 * Filesystem entries for the ROM0 ("/ram0")
	 */
	fent_t _rom0_fs_entries[ROM0FS_NUM_ENTRIES];
} SRAMWork;

#define sramwork_p ((SRAMWork*) 0x0000)
#define root_fs_entries sramwork_p->_root_fs_entries
#define rom0_fs_entries sramwork_p->_rom0_fs_entries
#define ram0_fs_entries sramwork_p->_ram0_fs_entries

/**
 * Root filesystem.
 */
#define root_fs (&root_fs_entries[0])

/**
 * Kernel directory ("/kern") filesystem.
 */
#define kern_fs (&root_fs_entries[1])

/**
 * ROM0 ("/rom0") filesystem.
 */
#define rom0_fs (&root_fs_entries[2])

/**
 * RAM0 ("/ram0") filesystem.
 */
#define ram0_fs (&root_fs_entries[3])

#endif /* __LIBWW_SYS_OSWORK_H__ */
