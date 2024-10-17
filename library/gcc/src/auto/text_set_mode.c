#include <sys/types.h>

void text_set_mode(uint16_t value) {
	uint16_t result;
	__asm volatile (
		"int $0x13"
		: "=a" (result)
		: "b" (value), "Rah" ((uint8_t) 0x02)
		: "cc", "memory"
	);
}
