#include <sys/types.h>

void screen_fill_attr(uint8_t screen_id, uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint16_t tile, uint16_t mask) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "a" ((uint16_t) (((0x0A) << 8) | (screen_id & 0xFF))), "d" (tile), "S" (mask), "b" (((y << 8) | x)), "c" (((height << 8) | width))
		: "cc", "memory"
	);
}
