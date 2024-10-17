#include <sys/types.h>

void sys_set_awake_key(uint16_t value) {
	uint16_t result;
	__asm volatile (
		"int $0x17"
		: "=a" (result)
		: "b" (value), "Rah" ((uint8_t) 0x07)
		: "cc", "memory"
	);
}
