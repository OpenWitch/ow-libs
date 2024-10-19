#include <sys/types.h>

#ifndef __LIBWW_STDLIB_H__
#define __LIBWW_STDLIB_H__

#include <stdint.h>

// The WonderWitch stdlib.h augments the libc-provided stdlib.h with some
// additional, non-standard instructions.
#include <_stdlib.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

#endif /* __LIBWW_STDLIB_H__ */
