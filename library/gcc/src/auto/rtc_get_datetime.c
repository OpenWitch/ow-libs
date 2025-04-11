#include <sys/types.h>

uint16_t rtc_get_datetime(uint16_t field) {
	uint16_t result;
	__asm volatile (
		"int $0x16"
		: "=a" (result)
		: "b" (field), "Rah" ((uint8_t) 0x02)
		: "cc", "memory"
	);
	return (uint16_t) result;
}
