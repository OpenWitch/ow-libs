#include <sys/types.h>

int16_t comm_send_block(const void __far* data, uint16_t length) {
	uint16_t result;
	__asm volatile (
		"int $0x14"
		: "=a" (result)
		: "Rds" (FP_SEG(data)), "d" (FP_OFF(data)), "c" (length), "Rah" ((uint8_t) 0x06)
		: "cc", "memory"
	);
	return result;
}
