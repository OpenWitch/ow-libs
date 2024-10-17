#include <sys/types.h>

void screen_set_scroll(uint8_t id, uint8_t x, uint8_t y) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "a" ((uint16_t) (((0x13) << 8) | (id & 0xFF))), "b" (((y << 8) | x))
		: "cc", "memory"
	);
}
