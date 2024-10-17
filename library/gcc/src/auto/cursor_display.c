#include <sys/types.h>

void cursor_display(uint8_t value) {
	uint16_t result;
	__asm volatile (
		"int $0x13"
		: "=a" (result)
		: "a" ((uint16_t) (((0x10) << 8) | (value & 0xFF)))
		: "cc", "memory"
	);
}
