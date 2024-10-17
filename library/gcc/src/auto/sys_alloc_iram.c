#include <sys/types.h>

void __wf_iram* sys_alloc_iram(void* ptr, uint16_t size) {
	uint16_t result;
	__asm volatile (
		"int $0x17"
		: "=a" (result)
		: "b" (ptr), "c" (size), "Rah" ((uint8_t) 0x0F)
		: "cc", "memory"
	);
	return result;
}
