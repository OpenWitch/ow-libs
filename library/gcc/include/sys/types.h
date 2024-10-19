#ifndef __LIBWW_SYS_TYPES_H__
#define __LIBWW_SYS_TYPES_H__

// This type header is written with the Wonderful toolchain libc in mind;
// as such, we don't duplicate types defined in the C standard.

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <time.h>
#include <wonderful.h>

typedef unsigned short ushort;
typedef unsigned long ulong;

typedef uint8_t BYTE;
typedef uint16_t WORD;
typedef uint32_t DWORD;
typedef int16_t BOOL;

#define FALSE 0
#define TRUE 1

// Compatibility shims
#define far __far
#define near

// FreyaBIOS types
struct intvector {
    void (*callback)(void);
    uint16_t cs;
    uint16_t ds;
    uint16_t unknown; /* ? */
};
typedef struct intvector intvector_t;

struct ownerinfo {
    char name[16];
    uint16_t birth_year;
    uint8_t birth_month;
    uint8_t birth_day;
    uint8_t sex;
    uint8_t bloodtype;
};
typedef struct ownerinfo ownerinfo_t;

struct datetime {
    uint8_t year;
    uint8_t month;
    uint8_t date;
    uint8_t day_of_week;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
};
typedef struct datetime datetime_t;

// FreyaOS system types
typedef uint16_t pid_t;
typedef int32_t flen_t;
typedef int32_t fpos_t;
typedef uint16_t fmode_t;
typedef uint32_t appid_t;

typedef union {
    void __far *fp;
    uint32_t ul;
    struct {
        uint16_t off;
        uint16_t seg;
    } w;
} address_t;
typedef address_t floc_t;

#endif /* __LIBWW_SYS_TYPES_H__ */
