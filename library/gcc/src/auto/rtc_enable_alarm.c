#include <sys/types.h>

void rtc_enable_alarm(uint8_t hour, uint8_t minute) {
	uint16_t result;
	__asm volatile (
		"int $0x16"
		: "=a" (result)
		: "b" (((minute << 8) | hour)), "Rah" ((uint8_t) 0x05)
		: "cc", "memory"
	);
}
