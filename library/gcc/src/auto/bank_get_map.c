#include <sys/types.h>

uint16_t bank_get_map(uint16_t bank_type) {
	uint16_t result;
	__asm volatile (
		"int $0x18"
		: "=a" (result)
		: "b" (bank_type), "Rah" ((uint8_t) 0x01)
		: "cc", "memory"
	);
	return result;
}
