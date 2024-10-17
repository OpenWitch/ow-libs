#include <sys/types.h>

uint16_t font_get_color(void) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x06)
		: "cc", "memory"
	);
	return result;
}
