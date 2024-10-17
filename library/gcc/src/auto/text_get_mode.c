#include <sys/types.h>

uint16_t text_get_mode(void) {
	uint16_t result;
	__asm volatile (
		"int $0x13"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x03)
		: "cc", "memory"
	);
	return result;
}
