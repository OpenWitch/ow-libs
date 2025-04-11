#include <sys/types.h>

uint32_t sprite_get_char_location(uint16_t id) {
	uint32_t result;
	__asm volatile (
		"int $0x12"
		: "=A" (result)
		: "b" (id), "Rah" ((uint8_t) 0x11)
		: "cc", "memory"
	);
	return (uint32_t) result;
}
