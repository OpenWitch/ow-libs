#include <sys/types.h>

uint16_t sys_get_version(void) {
	uint16_t result;
	__asm volatile (
		"int $0x17"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x12)
		: "cc", "memory"
	);
	return result;
}
