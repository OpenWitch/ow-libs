#include <sys/types.h>

void timer_enable(uint8_t type, uint16_t reload, uint16_t count) {
	uint16_t result;
	__asm volatile (
		"int $0x16"
		: "=a" (result)
		: "a" ((uint16_t) (((0x07) << 8) | (type & 0xFF))), "b" (reload), "c" (count)
		: "cc", "memory"
	);
}
