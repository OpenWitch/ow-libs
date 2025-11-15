#include <sys/types.h>

__attribute__((returns_twice))
uint16_t sys_swap(uint8_t slot) {
	uint16_t result;
	__asm volatile (
		"int $0x17"
		: "=a" (result)
		: "a" ((uint16_t) (((0x13) << 8) | (slot & 0xFF)))
		: "cc", "memory"
	);
	return (uint16_t) result;
}
