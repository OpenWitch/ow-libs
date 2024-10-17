#include <sys/types.h>

void sound_set_pitch(uint16_t channel, uint16_t value) {
	uint16_t result;
	__asm volatile (
		"int $0x15"
		: "=a" (result)
		: "a" ((uint16_t) (((0x06) << 8) | (channel & 0xFF))), "b" (value)
		: "cc", "memory"
	);
}
