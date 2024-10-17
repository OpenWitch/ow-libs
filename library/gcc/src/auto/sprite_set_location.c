#include <sys/types.h>

void sprite_set_location(uint16_t id, uint8_t x, uint8_t y) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "b" (id), "d" (((y << 8) | x)), "Rah" ((uint8_t) 0x0E)
		: "cc", "memory"
	);
}
