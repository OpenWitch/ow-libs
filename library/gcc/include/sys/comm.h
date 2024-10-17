#include <sys/types.h>

#ifndef __LIBWW_SYS_COMM_H__
#define __LIBWW_SYS_COMM_H__

/* Begin auto-generated section */

/* Serial port configuration flags */
/* 9600 bauds per second (960 bytes per second) */
#define COMM_SPEED_9600 0
/* 38400 bauds per second (3840 bytes per second) */
#define COMM_SPEED_38400 1

/* Error return codes */
/* Success */
#define ERR_SIO_OK 0
#define ERR_SIO_BUSY 0x8100
/* Serial operation timed out */
#define ERR_SIO_TIMEOUT 0x8101
/* Serial RX buffer overrun */
#define ERR_SIO_OVERRUN 0x8102
/* Serial operation cancelled by user */
#define ERR_SIO_CANCEL 0x8103
#define ERR_XM_STATECODE 0x8104
#define ERR_XM_CANCELED 0x8105
#define ERR_XM_BLOCK_LOST 0x8106
#define ERR_XM_TOO_LARGE 0x8107

static inline void comm_open(void) {
	uint16_t result;
	__asm volatile (
		"int $0x14"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x00)
		: "cc", "memory"
	);
}

static inline void comm_close(void) {
	uint16_t result;
	__asm volatile (
		"int $0x14"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x01)
		: "cc", "memory"
	);
}

/**
 * @param ch Character to send
 * @return Zero on success, negative on error
 */
static inline int16_t comm_send_char(uint8_t ch) {
	uint16_t result;
	__asm volatile (
		"int $0x14"
		: "=a" (result)
		: "b" (ch), "Rah" ((uint8_t) 0x02)
		: "cc", "memory"
	);
	return result;
}

/**
 * Receive a character using the default timeout.
 * @return Character read on success, negative on error
 */
static inline int16_t comm_receive_char(void) {
	uint16_t result;
	__asm volatile (
		"int $0x14"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x03)
		: "cc", "memory"
	);
	return result;
}

/**
 * Receive a character using an user-provided timeout.
 * @param timeout Timeout, in frames
 * @return Character read on success, negative on error
 */
static inline int16_t comm_receive_with_timeout(uint16_t timeout) {
	uint16_t result;
	__asm volatile (
		"int $0x14"
		: "=a" (result)
		: "c" (timeout), "Rah" ((uint8_t) 0x04)
		: "cc", "memory"
	);
	return result;
}

/**
 * @param str Input string to send
 * @return Return code
 */
int16_t comm_send_string(const char __far* str);

/**
 * @param data Data to send
 * @param length Length of data to send
 * @return Return code
 */
int16_t comm_send_block(const void __far* data, uint16_t length);

/**
 * @param data Data buffer
 * @param length Length of buffer, in bytes
 * @param out_length Length of data received, in bytes
 * @return Return code
 */
int16_t comm_receive_block(void __far* data, uint16_t length, int16_t __far* out_length);

/**
 * @param recv_timeout Receive timeout
 * @param send_timeout Send timeout
 */
static inline void comm_set_timeout(uint16_t recv_timeout, uint16_t send_timeout) {
	uint16_t result;
	__asm volatile (
		"int $0x14"
		: "=a" (result)
		: "b" (send_timeout), "Rah" ((uint8_t) 0x08)
		: "cc", "memory"
	);
}

/**
 * @param value New baud rate
 */
static inline void comm_set_baudrate(uint16_t value) {
	uint16_t result;
	__asm volatile (
		"int $0x14"
		: "=a" (result)
		: "b" (value), "Rah" ((uint8_t) 0x09)
		: "cc", "memory"
	);
}

/**
 * @return Current baud rate
 */
static inline uint16_t comm_get_baudrate(void) {
	uint16_t result;
	__asm volatile (
		"int $0x14"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x0A)
		: "cc", "memory"
	);
	return result;
}

/**
 * @param value New cancel key combination
 */
static inline void comm_set_cancel_key(uint16_t value) {
	uint16_t result;
	__asm volatile (
		"int $0x14"
		: "=a" (result)
		: "b" (value), "Rah" ((uint8_t) 0x0B)
		: "cc", "memory"
	);
}

/**
 * @return Current cancel key combination
 */
static inline uint16_t comm_get_cancel_key(void) {
	uint16_t result;
	__asm volatile (
		"int $0x14"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x0C)
		: "cc", "memory"
	);
	return result;
}

/* End auto-generated section */


#endif /* __LIBWW_SYS_COMM_H__ */
