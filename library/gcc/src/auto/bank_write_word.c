#include <sys/types.h>

void bank_write_word(uint16_t bank_id, uint16_t offset, uint16_t value) {
	uint16_t result;
	__asm volatile (
		"int $0x18"
		: "=a" (result)
		: "b" (bank_id), "d" (offset), "c" (value), "Rah" ((uint8_t) 0x05)
		: "cc", "memory"
	);
}
