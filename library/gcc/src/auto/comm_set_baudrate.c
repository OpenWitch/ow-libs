#include <sys/types.h>

void comm_set_baudrate(uint16_t value) {
	uint16_t result;
	__asm volatile (
		"int $0x14"
		: "=a" (result)
		: "b" (value), "Rah" ((uint8_t) 0x09)
		: "cc", "memory"
	);
}
