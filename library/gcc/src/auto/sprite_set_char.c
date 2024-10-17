#include <sys/types.h>

void sprite_set_char(uint16_t id, uint16_t tile) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "b" (id), "c" (tile), "Rah" ((uint8_t) 0x0C)
		: "cc", "memory"
	);
}
