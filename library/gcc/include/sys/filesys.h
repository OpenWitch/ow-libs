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


#endif /* __LIBWW_SYS_FILESYS_H__ */
