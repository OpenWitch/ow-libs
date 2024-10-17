#include <sys/types.h>

void bank_set_map(uint16_t bank_type, uint16_t bank) {
	uint16_t result;
	__asm volatile (
		"int $0x18"
		: "=a" (result)
		: "b" (bank_type), "c" (bank), "Rah" ((uint8_t) 0x00)
		: "cc", "memory"
	);
}
