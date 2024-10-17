#include <sys/types.h>

void text_fill_char(uint8_t x, uint8_t y, uint16_t length, uint16_t ch) {
	uint16_t result;
	__asm volatile (
		"int $0x13"
		: "=a" (result)
		: "c" (length), "d" (ch), "b" (((y << 8) | x)), "Rah" ((uint8_t) 0x08)
		: "cc", "memory"
	);
}
