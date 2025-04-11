#include <sys/types.h>

int16_t comm_send_string(const char __far* str) {
	uint16_t result;
	__asm volatile (
		"int $0x14"
		: "=a" (result)
		: "Rds" (FP_SEG(str)), "d" (FP_OFF(str)), "Rah" ((uint8_t) 0x05)
		: "cc", "memory"
	);
	return (int16_t) result;
}
