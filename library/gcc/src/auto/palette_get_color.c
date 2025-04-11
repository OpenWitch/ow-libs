#include <sys/types.h>

uint16_t palette_get_color(uint16_t index) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "b" (index), "Rah" ((uint8_t) 0x1A)
		: "cc", "memory"
	);
	return (uint16_t) result;
}
