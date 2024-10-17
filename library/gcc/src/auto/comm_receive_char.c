#include <sys/types.h>

int16_t comm_receive_char(void) {
	uint16_t result;
	__asm volatile (
		"int $0x14"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x03)
		: "cc", "memory"
	);
	return result;
}
