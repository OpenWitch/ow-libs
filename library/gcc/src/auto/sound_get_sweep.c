#include <sys/types.h>

uint16_t sound_get_sweep(void) {
	uint16_t result;
	__asm volatile (
		"int $0x15"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x0B)
		: "cc", "memory"
	);
	return result;
}
