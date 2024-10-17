#include <sys/types.h>

void key_set_repeat(uint8_t delay, uint8_t rate) {
	uint16_t result;
	__asm volatile (
		"int $0x11"
		: "=a" (result)
		: "b" (((rate << 8) | delay)), "Rah" ((uint8_t) 0x03)
		: "cc", "memory"
	);
}
