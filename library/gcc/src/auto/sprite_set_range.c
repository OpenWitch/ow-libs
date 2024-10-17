#include <sys/types.h>

void sprite_set_range(uint16_t first, uint16_t count) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "b" (first), "c" (count), "Rah" ((uint8_t) 0x0B)
		: "cc", "memory"
	);
}
