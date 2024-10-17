#include <sys/types.h>

void font_set_color(uint16_t value) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "b" (value), "Rah" ((uint8_t) 0x05)
		: "cc", "memory"
	);
}
