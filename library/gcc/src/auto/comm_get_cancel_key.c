#include <sys/types.h>

uint16_t comm_get_cancel_key(void) {
	uint16_t result;
	__asm volatile (
		"int $0x14"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x0C)
		: "cc", "memory"
	);
	return result;
}
