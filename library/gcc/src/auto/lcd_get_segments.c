#include <sys/types.h>

uint16_t lcd_get_segments(void) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x1E)
		: "cc", "memory"
	);
	return (uint16_t) result;
}
