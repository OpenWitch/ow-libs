#include <sys/types.h>

uint16_t text_get_fontdata(uint16_t ch, void __far* data) {
	uint16_t result;
	__asm volatile (
		"int $0x13"
		: "=a" (result)
		: "Rds" (FP_SEG(data)), "d" (FP_OFF(data)), "c" (ch), "Rah" ((uint8_t) 0x0D)
		: "cc", "memory"
	);
	return (uint16_t) result;
}
