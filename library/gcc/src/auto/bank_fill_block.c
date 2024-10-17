#include <sys/types.h>

void bank_fill_block(uint16_t bank_id, uint16_t offset, uint16_t length, uint8_t value) {
	uint16_t result;
	__asm volatile (
		"int $0x18"
		: "=a" (result)
		: "a" ((uint16_t) (((0x08) << 8) | (value & 0xFF))), "b" (bank_id), "d" (offset), "c" (length)
		: "cc", "memory"
	);
}
