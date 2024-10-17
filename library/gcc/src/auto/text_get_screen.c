#include <sys/types.h>

uint8_t text_get_screen(void) {
	uint16_t result;
	__asm volatile (
		"int $0x13"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x0F)
		: "cc", "memory"
	);
	return result;
}
