#include <sys/types.h>

void sys_wait(uint16_t ticks) {
	uint16_t result;
	__asm volatile (
		"int $0x17"
		: "=a" (result)
		: "c" (ticks), "Rah" ((uint8_t) 0x02)
		: "cc", "memory"
	);
}
