#include <sys/types.h>

uint16_t display_status(void) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x01)
		: "cc", "memory"
	);
	return (uint16_t) result;
}
