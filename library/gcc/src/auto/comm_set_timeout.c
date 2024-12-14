#include <sys/types.h>

void comm_set_timeout(uint16_t recv_timeout, uint16_t send_timeout) {
	uint16_t result;
	__asm volatile (
		"int $0x14"
		: "=a" (result)
		: "b" (recv_timeout), "c" (send_timeout), "Rah" ((uint8_t) 0x08)
		: "cc", "memory"
	);
}
