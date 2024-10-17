#include <sys/types.h>

uint32_t screen2_get_window(void) {
	uint32_t result;
	__asm volatile (
		"int $0x12"
		: "=A" (result)
		: "Rah" ((uint8_t) 0x16)
		: "cc", "memory"
	);
	return result;
}
