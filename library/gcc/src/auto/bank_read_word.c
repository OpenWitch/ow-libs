#include <sys/types.h>

uint8_t bank_read_word(uint16_t bank_id, uint16_t offset) {
	uint16_t result;
	__asm volatile (
		"int $0x18"
		: "=a" (result)
		: "b" (bank_id), "d" (offset), "Rah" ((uint8_t) 0x04)
		: "cc", "memory"
	);
	return (uint8_t) result;
}
