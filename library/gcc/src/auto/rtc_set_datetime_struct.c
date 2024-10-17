#include <sys/types.h>

void rtc_set_datetime_struct(const datetime_t __far* value) {
	uint16_t result;
	__asm volatile (
		"int $0x16"
		: "=a" (result)
		: "Rds" (FP_SEG(value)), "d" (FP_OFF(value)), "Rah" ((uint8_t) 0x03)
		: "cc", "memory"
	);
}
