#include <sys/types.h>

void sys_resume(uint8_t slot) {
	uint16_t result;
	__asm volatile (
		"int $0x17"
		: "=a" (result)
		: "a" ((uint16_t) (((0x0C) << 8) | (slot & 0xFF)))
		: "cc", "memory"
	);
}
