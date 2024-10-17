#include <sys/types.h>

void rtc_get_datetime_struct(datetime_t __far* value) {
	uint16_t result;
	__asm volatile (
		"int $0x16"
		: "=a" (result)
		: "Rds" (FP_SEG(value)), "d" (FP_OFF(value)), "Rah" ((uint8_t) 0x04)
		: "cc", "memory"
	);
}
