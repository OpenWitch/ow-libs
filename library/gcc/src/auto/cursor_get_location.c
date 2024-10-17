#include <sys/types.h>

uint32_t cursor_get_location(void) {
	uint32_t result;
	__asm volatile (
		"int $0x13"
		: "=A" (result)
		: "Rah" ((uint8_t) 0x13)
		: "cc", "memory"
	);
	return result;
}
