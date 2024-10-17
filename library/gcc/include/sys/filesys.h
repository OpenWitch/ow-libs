#include <sys/types.h>

#ifndef __LIBWW_SYS_FILESYS_H__
#define __LIBWW_SYS_FILESYS_H__

/* Begin auto-generated section */

#define MAXFNAME 16
#define MAXPATHLEN 64
#define MAXFINFO 24

#define FMODE_X 0x01
#define FMODE_W 0x02
#define FMODE_R 0x04
#define FMODE_MMAP 0x08
#define FMODE_STREAM 0x10
#define FMODE_ILIB 0x20
#define FMODE_LINK 0x40
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
