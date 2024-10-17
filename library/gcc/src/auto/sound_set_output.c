#include <sys/types.h>

void sound_set_output(uint16_t value) {
	uint16_t result;
	__asm volatile (
		"int $0x15"
		: "=a" (result)
		: "b" (value), "Rah" ((uint8_t) 0x03)
		: "cc", "memory"
	);
}
