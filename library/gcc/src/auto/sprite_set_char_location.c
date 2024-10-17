#include <sys/types.h>

void sprite_set_char_location(uint16_t id, uint16_t tile, uint8_t x, uint8_t y) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "b" (id), "c" (tile), "d" (((y << 8) | x)), "Rah" ((uint8_t) 0x10)
		: "cc", "memory"
	);
}
