#include <sys/types.h>

uint32_t lcd_get_color(void) {
	uint32_t result;
	__asm volatile (
		"int $0x12"
		: "=A" (result)
		: "Rah" ((uint8_t) 0x1C)
		: "cc", "memory"
	);
	return result;
}
