#include <sys/types.h>

uint16_t key_wait(void) {
	uint16_t result;
	__asm volatile (
		"int $0x11"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x02)
		: "cc", "memory"
	);
	return result;
}
