#include <sys/types.h>

uint16_t text_get_palette(void) {
	uint16_t result;
	__asm volatile (
		"int $0x13"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x0A)
		: "cc", "memory"
	);
	return (uint16_t) result;
}
