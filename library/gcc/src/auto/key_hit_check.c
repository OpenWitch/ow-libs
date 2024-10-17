#include <sys/types.h>

uint16_t key_hit_check(void) {
	uint16_t result;
	__asm volatile (
		"int $0x11"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x01)
		: "cc", "memory"
	);
	return result;
}
