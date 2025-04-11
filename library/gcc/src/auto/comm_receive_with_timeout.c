#include <sys/types.h>

int16_t comm_receive_with_timeout(uint16_t timeout) {
	uint16_t result;
	__asm volatile (
		"int $0x14"
		: "=a" (result)
		: "c" (timeout), "Rah" ((uint8_t) 0x04)
		: "cc", "memory"
	);
	return (int16_t) result;
}
