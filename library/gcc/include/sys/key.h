#include <sys/types.h>

#ifndef __LIBWW_SYS_KEY_H__
#define __LIBWW_SYS_KEY_H__

/* Begin auto-generated section */

/* Key masks */
#define KEY_Y4 0x0800
#define KEY_Y3 0x0400
#define KEY_Y2 0x0200
#define KEY_Y1 0x0100
#define KEY_X4 0x0080
#define KEY_X3 0x0040
#define KEY_X2 0x0020
#define KEY_X1 0x0010
#define KEY_B 0x0008
#define KEY_A 0x0004
#define KEY_START 0x0002

#define KEY_UP1 KEY_X1
#define KEY_RIGHT1 KEY_X2
#define KEY_DOWN1 KEY_X3
#define KEY_LEFT1 KEY_X4
#define KEY_UP2 KEY_Y1
#define KEY_RIGHT2 KEY_Y2
#define KEY_DOWN2 KEY_Y3
#define KEY_LEFT2 KEY_Y4

/**
 * Check for currently held keys.
 * @return Mask of currently held keys
 */
static inline uint16_t key_press_check(void) {
	uint16_t result;
	__asm volatile (
		"int $0x11"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x00)
		: "cc", "memory"
	);
	return (uint16_t) result;
}

/**
 * Check for newly pressed keys.
 * @return Mask of newly pressed keys
 */
static inline uint16_t key_hit_check(void) {
	uint16_t result;
	__asm volatile (
		"int $0x11"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x01)
		: "cc", "memory"
	);
	return (uint16_t) result;
}

/**
 * Wait until a key is pressed.
 * @return Mask of newly pressed keys
 */
static inline uint16_t key_wait(void) {
	uint16_t result;
	__asm volatile (
		"int $0x11"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x02)
		: "cc", "memory"
	);
	return (uint16_t) result;
}

static inline void key_set_repeat(uint8_t delay, uint8_t rate) {
	uint16_t result;
	__asm volatile (
		"int $0x11"
		: "=a" (result)
		: "b" (((rate << 8) | delay)), "Rah" ((uint8_t) 0x03)
		: "cc", "memory"
	);
}

static inline uint16_t key_get_repeat(void) {
	uint16_t result;
	__asm volatile (
		"int $0x11"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x04)
		: "cc", "memory"
	);
	return (uint16_t) result;
}

/**
 * Check for newly pressed keys, taking into account the repeat delay/rate configuration.
 * @return Mask of newly pressed keys
 */
static inline uint16_t key_hit_check_with_repeat(void) {
	uint16_t result;
	__asm volatile (
		"int $0x11"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x05)
		: "cc", "memory"
	);
	return (uint16_t) result;
}

/* End auto-generated section */


#endif /* __LIBWW_SYS_KEY_H__ */
