#include <sys/types.h>

void rtc_reset(void) {
	uint16_t result;
	__asm volatile (
		"int $0x16"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x00)
		: "cc", "memory"
	);
}
