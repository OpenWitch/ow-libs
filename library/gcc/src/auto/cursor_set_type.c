#include <sys/types.h>

void cursor_set_type(uint8_t palette, uint8_t rate) {
	uint16_t result;
	__asm volatile (
		"int $0x13"
		: "=a" (result)
		: "b" (palette), "c" (rate), "Rah" ((uint8_t) 0x14)
		: "cc", "memory"
	);
}
