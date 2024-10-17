#include <sys/types.h>

void lcd_set_color(uint16_t low, uint16_t high) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "b" (low), "c" (high), "Rah" ((uint8_t) 0x1B)
		: "cc", "memory"
	);
}
