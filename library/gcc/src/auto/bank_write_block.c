#include <sys/types.h>

void bank_write_block(uint16_t bank_id, uint16_t offset, const void __far* data, uint16_t length) {
	uint16_t result;
	__asm volatile (
		"int $0x18"
		: "=a" (result)
		: "Rds" (FP_SEG(data)), "S" (FP_OFF(data)), "b" (bank_id), "d" (offset), "c" (length), "Rah" ((uint8_t) 0x07)
		: "cc", "memory"
	);
}
