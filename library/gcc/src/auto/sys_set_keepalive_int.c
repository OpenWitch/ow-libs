#include <sys/types.h>

void sys_set_keepalive_int(uint16_t value) {
	uint16_t result;
	__asm volatile (
		"int $0x17"
		: "=a" (result)
		: "b" (value), "Rah" ((uint8_t) 0x09)
		: "cc", "memory"
	);
}
