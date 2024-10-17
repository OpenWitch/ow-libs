#include <sys/types.h>

uint16_t lcd_get_sleep(void) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x20)
		: "cc", "memory"
	);
	return result;
}
