#ifndef __LIBWW_SYS_TYPES_H__
#define __LIBWW_SYS_TYPES_H__

#include <stddef.h>
#include <stdint.h>
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

#endif /* __LIBWW_SYS_TYPES_H__ */
