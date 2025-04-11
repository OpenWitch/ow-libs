#include <sys/types.h>

uint16_t sys_get_sleep_time(void) {
	uint16_t result;
	__asm volatile (
		"int $0x17"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x06)
		: "cc", "memory"
	);
	return (uint16_t) result;
}
