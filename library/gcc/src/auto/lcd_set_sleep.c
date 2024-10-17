#include <sys/types.h>

void lcd_set_sleep(uint16_t flags) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "b" (flags), "Rah" ((uint8_t) 0x1F)
		: "cc", "memory"
	);
}
