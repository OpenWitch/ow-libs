#include <sys/types.h>

void cursor_set_location(uint8_t x, uint8_t y, uint8_t width, uint8_t height) {
	uint16_t result;
	__asm volatile (
		"int $0x13"
		: "=a" (result)
		: "b" (((y << 8) | x)), "c" (((height << 8) | width)), "Rah" ((uint8_t) 0x12)
		: "cc", "memory"
	);
}
