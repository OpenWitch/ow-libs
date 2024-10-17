#include <sys/types.h>

void bios_exit(void) {
	uint16_t result;
	__asm volatile (
		"int $0x10"
		: "=a" (result)
		:
		: "cc", "memory"
	);
}
