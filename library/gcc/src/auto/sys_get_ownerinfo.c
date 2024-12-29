#include <sys/types.h>

uint16_t sys_get_ownerinfo(uint16_t size, void __far* data) {
	uint16_t result;
	__asm volatile (
		"int $0x17"
		: "=a" (result)
		: "Rds" (FP_SEG(data)), "d" (FP_OFF(data)), "c" (size), "Rah" ((uint8_t) 0x0A)
		: "cc", "memory"
	);
	return result;
}
