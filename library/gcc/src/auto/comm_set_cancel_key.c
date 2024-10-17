#include <sys/types.h>

void comm_set_cancel_key(uint16_t value) {
	uint16_t result;
	__asm volatile (
		"int $0x14"
		: "=a" (result)
		: "b" (value), "Rah" ((uint8_t) 0x0B)
		: "cc", "memory"
	);
}
