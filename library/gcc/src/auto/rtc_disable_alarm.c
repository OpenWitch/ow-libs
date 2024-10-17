#include <sys/types.h>

void rtc_disable_alarm(void) {
	uint16_t result;
	__asm volatile (
		"int $0x16"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x06)
		: "cc", "memory"
	);
}
