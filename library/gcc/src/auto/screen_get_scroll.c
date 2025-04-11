#include <sys/types.h>

uint16_t screen_get_scroll(uint8_t id) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "a" ((uint16_t) (((0x14) << 8) | (id & 0xFF)))
		: "cc", "memory"
	);
	return (uint16_t) result;
}
