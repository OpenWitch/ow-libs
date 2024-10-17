#include <sys/types.h>

void text_set_screen(uint8_t id) {
	uint16_t result;
	__asm volatile (
		"int $0x13"
		: "=a" (result)
		: "a" ((uint16_t) (((0x0E) << 8) | (id & 0xFF)))
		: "cc", "memory"
	);
}
