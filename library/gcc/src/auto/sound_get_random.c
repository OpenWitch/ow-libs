#include <sys/types.h>

uint16_t sound_get_random(void) {
	uint16_t result;
	__asm volatile (
		"int $0x15"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x0E)
		: "cc", "memory"
	);
	return (uint16_t) result;
}
