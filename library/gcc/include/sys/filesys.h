#include <sys/types.h>

#ifndef __LIBWW_SYS_FILESYS_H__
#define __LIBWW_SYS_FILESYS_H__

/* Begin auto-generated section */

/* 
 * Maximum file name length.
 * 
*/
#define MAXFNAME 16
/* 
 * Maximum file path length.
 * 
*/
#define MAXPATHLEN 64
/* 
 * Maximum file description length.
 * 
*/
#define MAXFINFO 24

/* 
 * File mode flag: Execute
 * 
*/
#define FMODE_X 0x01
/* 
 * File mode flag: Write
 * 
*/
#define FMODE_W 0x02
/* 
 * File mode flag: Read
 * 
*/
#define FMODE_R 0x04
#define FMODE_MMAP 0x08
#define FMODE_STREAM 0x10
/* 
 * File mode flag: Indirect Library
 * 
*/
#define FMODE_ILIB 0x20
/* 
 * File mode flag: Link
 * 
*/
#define FMODE_LINK 0x40
/* 
 * File mode flag: Directory
 * 
*/
#define FMODE_DIR 0x80

#define E_FS_SUCCESS 0
#define E_FS_ERROR 0x8000
#define E_FS_FILE_NOT_FOUND 0x8001
#define E_FS_PERMISSION_DENIED 0x8002
#define E_FS_OUT_OF_BOUNDS 0x8003
#define E_FS_NO_SPACE_LEFT 0x8004
#define E_FS_FILE_NOT_OPEN 0x8005
/* End auto-generated section */

struct _FsIL;
typedef struct {
	/**
	 * File name, encoded in Shift-JIS
	 */
	char name[MAXFNAME];

	/**
	 * File description, encoded in Shift-JIS
	 */
	char info[MAXFINFO];

	/**
	 * Location of file in file system
	 */
	void __far* loc;

	/**
	 * Length of file, in bytes
	 */
	uint32_t len;

	/**
	 * File: 128-byte (XMODEM) chunk count, rounded up.
	 * Directory: Number of total entries in directory.
	 * (-1 = entry not allocated)
	 */
	int count;

	/**
	 * File mode.
	 */
	uint16_t mode;

	/**
	 * Modification time.
	 */
	uint32_t mtime;

	/**
	 * Directory: FsIL library instance handling this
	 * directory.
	 */
	struct _FsIL __far* il;

	/**
	 * Offset of resource data in file, passed via the
	 * process control block to the program.
	 * (-1 = resource not present)
	 */
	int32_t resource;
} fent_t;

typedef fent_t __far* FS;

#endif /* __LIBWW_SYS_FILESYS_H__ */
