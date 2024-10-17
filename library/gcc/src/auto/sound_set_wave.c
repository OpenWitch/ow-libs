#include <sys/types.h>

void sound_set_wave(uint8_t channel, const void __far* data) {
	uint16_t result;
	__asm volatile (
		"int $0x15"
		: "=a" (result)
		: "a" ((uint16_t) (((0x05) << 8) | (channel & 0xFF))), "Rds" (FP_SEG(data)), "d" (FP_OFF(data))
		: "cc", "memory"
	);
}
