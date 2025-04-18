#include <sys/types.h>

uint16_t sys_get_tick_count(void) {
	uint16_t result;
	__asm volatile (
		"int $0x17"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x03)
		: "cc", "memory"
	);
	return (uint16_t) result;
}
