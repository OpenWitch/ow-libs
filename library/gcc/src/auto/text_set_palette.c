#include <sys/types.h>

void text_set_palette(uint16_t index) {
	uint16_t result;
	__asm volatile (
		"int $0x13"
		: "=a" (result)
		: "b" (index), "Rah" ((uint8_t) 0x09)
		: "cc", "memory"
	);
}
