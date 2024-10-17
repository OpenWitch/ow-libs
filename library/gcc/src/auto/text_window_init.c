#include <sys/types.h>

void text_window_init(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint16_t base) {
	uint16_t result;
	__asm volatile (
		"int $0x13"
		: "=a" (result)
		: "d" (base), "b" (((y << 8) | x)), "c" (((height << 8) | width)), "Rah" ((uint8_t) 0x01)
		: "cc", "memory"
	);
}
