#include <sys/types.h>

int16_t comm_send_char(uint8_t ch) {
	uint16_t result;
	__asm volatile (
		"int $0x14"
		: "=a" (result)
		: "b" (ch), "Rah" ((uint8_t) 0x02)
		: "cc", "memory"
	);
	return (int16_t) result;
}
