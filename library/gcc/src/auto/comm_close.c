#include <sys/types.h>

void comm_close(void) {
	uint16_t result;
	__asm volatile (
		"int $0x14"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x01)
		: "cc", "memory"
	);
}
