#include <sys/types.h>

void sys_free_iram(void __wf_iram* ptr) {
	uint16_t result;
	__asm volatile (
		"int $0x17"
		: "=a" (result)
		: "b" (ptr), "Rah" ((uint8_t) 0x10)
		: "cc", "memory"
	);
}
