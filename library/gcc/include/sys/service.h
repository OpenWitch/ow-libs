#include <sys/types.h>

#ifndef __LIBWW_SYS_SERVICE_H__
#define __LIBWW_SYS_SERVICE_H__

/* Begin auto-generated section */

static inline void bios_exit(void) {
	uint16_t result;
	__asm volatile (
		"int $0x10"
		: "=a" (result)
		:
		: "cc", "memory"
	);
}

/* End auto-generated section */


#endif /* __LIBWW_SYS_SERVICE_H__ */
