#include <sys/types.h>

uint16_t screen_get_char1(uint8_t screen_id, uint8_t x, uint8_t y) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "a" ((uint16_t) (((0x08) << 8) | (screen_id & 0xFF))), "b" (((y << 8) | x)), "c" ((uint16_t) 0)
		: "cc", "memory"
	);
	return (uint16_t) result;
}
