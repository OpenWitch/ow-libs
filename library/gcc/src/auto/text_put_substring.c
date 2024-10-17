#include <sys/types.h>

void text_put_substring(uint8_t x, uint8_t y, const char __far* str, uint16_t length) {
	uint16_t result;
	__asm volatile (
		"int $0x13"
		: "=a" (result)
		: "Rds" (FP_SEG(str)), "d" (FP_OFF(str)), "c" (length), "b" (((y << 8) | x)), "Rah" ((uint8_t) 0x06)
		: "cc", "memory"
	);
}
