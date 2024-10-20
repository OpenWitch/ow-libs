#include <sys/types.h>

uint16_t text_put_string(uint8_t x, uint8_t y, const char __far* str) {
	uint16_t result;
	__asm volatile (
		"int $0x13"
		: "=a" (result)
		: "Rds" (FP_SEG(str)), "d" (FP_OFF(str)), "b" (((y << 8) | x)), "Rah" ((uint8_t) 0x05)
		: "cc", "memory"
	);
	return result;
}
