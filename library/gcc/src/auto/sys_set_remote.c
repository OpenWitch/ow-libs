#include <sys/types.h>

void sys_set_remote(uint8_t value) {
	uint16_t result;
	__asm volatile (
		"int $0x17"
		: "=a" (result)
		: "a" ((uint16_t) (((0x0D) << 8) | (value & 0xFF)))
		: "cc", "memory"
	);
}
