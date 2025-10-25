#include <sys/types.h>

void text_set_sjis_font(void __far* handler) {
	uint16_t result;
	__asm volatile (
		"int $0x13"
		: "=a" (result)
		: "b" (FP_SEG(handler)), "d" (FP_OFF(handler)), "Rah" ((uint8_t) 0x0C)
		: "cc", "memory"
	);
}
