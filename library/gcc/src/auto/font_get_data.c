#include <sys/types.h>

void font_get_data(uint16_t start, uint16_t count, void __far* data) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "Rds" (FP_SEG(data)), "d" (FP_OFF(data)), "b" (start), "c" (count), "Rah" ((uint8_t) 0x04)
		: "cc", "memory"
	);
}
