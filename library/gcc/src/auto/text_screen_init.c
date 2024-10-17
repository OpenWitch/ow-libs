#include <sys/types.h>

void text_screen_init(void) {
	uint16_t result;
	__asm volatile (
		"int $0x13"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x00)
		: "cc", "memory"
	);
}
