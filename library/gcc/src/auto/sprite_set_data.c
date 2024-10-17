#include <sys/types.h>

void sprite_set_data(uint16_t first, uint16_t count, const void __far* data) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "Rds" (FP_SEG(data)), "d" (FP_OFF(data)), "b" (first), "c" (count), "Rah" ((uint8_t) 0x12)
		: "cc", "memory"
	);
}
