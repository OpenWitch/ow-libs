#include <sys/types.h>

uint16_t key_press_check(void) {
	uint16_t result;
	__asm volatile (
		"int $0x11"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x00)
		: "cc", "memory"
	);
	return result;
}
