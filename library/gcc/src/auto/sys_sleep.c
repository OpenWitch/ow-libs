#include <sys/types.h>

void sys_sleep(void) {
	uint16_t result;
	__asm volatile (
		"int $0x17"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x04)
		: "cc", "memory"
	);
}
