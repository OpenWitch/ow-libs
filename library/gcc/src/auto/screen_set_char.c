#include <sys/types.h>

void screen_set_char(uint8_t screen_id, uint8_t x, uint8_t y, uint8_t width, uint8_t height, const void __far* tiles) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "a" ((uint16_t) (((0x07) << 8) | (screen_id & 0xFF))), "Rds" (FP_SEG(tiles)), "d" (FP_OFF(tiles)), "b" (((y << 8) | x)), "c" (((height << 8) | width))
		: "cc", "memory"
	);
}
