#include <sys/types.h>

uint16_t sound_get_volume(uint16_t channel) {
	uint16_t result;
	__asm volatile (
		"int $0x15"
		: "=a" (result)
		: "a" ((uint16_t) (((0x09) << 8) | (channel & 0xFF)))
		: "cc", "memory"
	);
	return result;
}
