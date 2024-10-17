#include <sys/types.h>

void timer_get_count(uint8_t type) {
	uint16_t result;
	__asm volatile (
		"int $0x16"
		: "=a" (result)
		: "a" ((uint16_t) (((0x09) << 8) | (type & 0xFF)))
		: "cc", "memory"
	);
}
