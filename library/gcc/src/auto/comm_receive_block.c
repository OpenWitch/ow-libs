#include <sys/types.h>

int16_t comm_receive_block(void __far* data, uint16_t length, int16_t __far* out_length) {
	uint16_t result;
	int16_t _out_length;
	__asm volatile (
		"int $0x14"
		: "=a" (result), "=d" (_out_length)
		: "Rds" (FP_SEG(data)), "d" (FP_OFF(data)), "c" (length), "Rah" ((uint8_t) 0x07)
		: "cc", "memory"
	);
	if (out_length) *out_length = _out_length;
	return (int16_t) result;
}
