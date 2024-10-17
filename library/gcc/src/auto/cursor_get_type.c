#include <sys/types.h>

uint16_t cursor_get_type(void) {
	uint16_t result;
	__asm volatile (
		"int $0x13"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x15)
		: "cc", "memory"
	);
	return result;
}
