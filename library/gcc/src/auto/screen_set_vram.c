#include <sys/types.h>

void screen_set_vram(uint8_t id, uint8_t offset) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "a" ((uint16_t) (((0x21) << 8) | (id & 0xFF))), "b" (offset)
		: "cc", "memory"
	);
}
