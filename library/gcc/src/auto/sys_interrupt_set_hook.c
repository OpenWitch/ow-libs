#include <sys/types.h>

void sys_interrupt_set_hook(uint8_t id, intvector_t __far* new_vector, intvector_t __far* old_vector) {
	uint16_t result;
	__asm volatile (
		"int $0x17"
		: "=a" (result)
		: "a" ((uint16_t) (((0x00) << 8) | (id & 0xFF))), "Rds" (FP_SEG(new_vector)), "b" (FP_OFF(new_vector)), "d" (FP_OFF(old_vector))
		: "cc", "memory"
	);
}
