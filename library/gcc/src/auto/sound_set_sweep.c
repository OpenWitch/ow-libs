#include <sys/types.h>

void sound_set_sweep(uint8_t sweep, uint8_t step_time) {
	uint16_t result;
	__asm volatile (
		"int $0x15"
		: "=a" (result)
		: "b" (sweep), "c" (step_time), "Rah" ((uint8_t) 0x0A)
		: "cc", "memory"
	);
}
