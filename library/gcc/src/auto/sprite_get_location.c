#include <sys/types.h>

uint16_t sprite_get_location(uint16_t id) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "b" (id), "Rah" ((uint8_t) 0x0F)
		: "cc", "memory"
	);
	return (uint16_t) result;
}
