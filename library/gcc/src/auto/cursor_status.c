#include <sys/types.h>

uint8_t cursor_status(void) {
	uint16_t result;
	__asm volatile (
		"int $0x13"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x11)
		: "cc", "memory"
	);
	return (uint8_t) result;
}
