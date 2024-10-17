#include <sys/types.h>

void display_control(uint16_t value) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "b" (value), "Rah" ((uint8_t) 0x00)
		: "cc", "memory"
	);
}
