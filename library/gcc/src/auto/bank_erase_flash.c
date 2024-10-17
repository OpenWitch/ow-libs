#include <sys/types.h>

void bank_erase_flash(uint16_t bank_id) {
	uint16_t result;
	__asm volatile (
		"int $0x18"
		: "=a" (result)
		: "b" (bank_id), "Rah" ((uint8_t) 0x09)
		: "cc", "memory"
	);
}
