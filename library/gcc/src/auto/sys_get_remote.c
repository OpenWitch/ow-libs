#include <sys/types.h>

uint8_t sys_get_remote(void) {
	uint16_t result;
	__asm volatile (
		"int $0x17"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x0E)
		: "cc", "memory"
	);
	return (uint8_t) result;
}
