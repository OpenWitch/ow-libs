#include <sys/types.h>

void rtc_set_datetime(uint16_t field, uint16_t value) {
	uint16_t result;
	__asm volatile (
		"int $0x16"
		: "=a" (result)
		: "b" (field), "c" (value), "Rah" ((uint8_t) 0x01)
		: "cc", "memory"
	);
}
