#include <sys/types.h>

uint16_t key_hit_check_with_repeat(void) {
	uint16_t result;
	__asm volatile (
		"int $0x11"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x05)
		: "cc", "memory"
	);
	return (uint16_t) result;
}
