#include <sys/types.h>

void comm_open(void) {
	uint16_t result;
	__asm volatile (
		"int $0x14"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x00)
		: "cc", "memory"
	);
}
