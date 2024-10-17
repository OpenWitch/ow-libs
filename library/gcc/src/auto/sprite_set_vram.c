#include <sys/types.h>

void sprite_set_vram(uint8_t offset) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "b" (offset), "Rah" ((uint8_t) 0x22)
		: "cc", "memory"
	);
}
