#include <sys/types.h>

void text_set_ank_font(uint8_t start, uint8_t depth, uint16_t count, const void __far* data) {
	uint16_t result;
	__asm volatile (
		"int $0x13"
		: "=a" (result)
		: "Rds" (FP_SEG(data)), "d" (FP_OFF(data)), "c" (count), "b" (((depth << 8) | start)), "Rah" ((uint8_t) 0x0B)
		: "cc", "memory"
	);
}
