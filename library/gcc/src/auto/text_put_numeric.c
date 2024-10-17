#include <sys/types.h>

void text_put_numeric(uint8_t x, uint8_t y, uint8_t width, uint8_t flags, uint16_t value) {
	uint16_t result;
	__asm volatile (
		"int $0x13"
		: "=a" (result)
		: "d" (value), "b" (((y << 8) | x)), "c" (((flags << 8) | width)), "Rah" ((uint8_t) 0x07)
		: "cc", "memory"
	);
}
