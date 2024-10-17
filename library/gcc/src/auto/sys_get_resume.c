#include <sys/types.h>

uint16_t sys_get_resume(void) {
	uint16_t result;
	__asm volatile (
		"int $0x17"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x15)
		: "cc", "memory"
	);
	return result;
}
