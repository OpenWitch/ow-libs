#include <sys/types.h>

uint16_t text_store_numeric(void __far* buffer, uint8_t width, uint8_t flags, uint16_t value) {
	uint16_t result;
	flags = flags | 0x80;
	__asm volatile (
		"int $0x13"
		: "=a" (result)
		: "Rds" (FP_SEG(buffer)), "b" (FP_OFF(buffer)), "d" (value), "c" (((flags << 8) | width)), "Rah" ((uint8_t) 0x07)
		: "cc", "memory"
	);
	return result;
}
