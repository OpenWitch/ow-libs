#include <sys/types.h>

void __wf_iram* sys_get_my_iram(void) {
	uint16_t result;
	__asm volatile (
		"int $0x17"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x11)
		: "cc", "memory"
	);
	return result;
}
