#include <sys/types.h>

void palette_set_color(uint16_t index, uint16_t colors) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "b" (index), "c" (colors), "Rah" ((uint8_t) 0x19)
		: "cc", "memory"
	);
}
