#include <sys/types.h>

#ifndef __LIBWW_SYS_SYSTEM_H__
#define __LIBWW_SYS_SYSTEM_H__

/* Begin auto-generated section */

/* Hardware interrupt vectors */
/* Serial TX ready */
#define SYS_INT_SENDREADY 0
/* Key pressed */
#define SYS_INT_KEY 1
/* Cartridge IRQ */
#define SYS_INT_CASETTE 2
/* Serial RX ready */
#define SYS_INT_RECEIVEREADY 3
/* Display interrupt line match */
#define SYS_INT_DISPLINE 4
/* VBlank Timer */
#define SYS_INT_TIMER_COUNTUP 5
/* VBlank */
#define SYS_INT_VBLANK 6
/* HBlank Timer */
#define SYS_INT_HBLANK_COUNTUP 7

void sys_interrupt_set_hook(uint8_t id, intvector_t __far* new_vector, intvector_t __far* old_vector);

void sys_interrupt_reset_hook(uint8_t id, intvector_t __far* old_vector);

static inline void sys_wait(uint16_t ticks) {
	uint16_t result;
	__asm volatile (
		"int $0x17"
		: "=a" (result)
		: "c" (ticks), "Rah" ((uint8_t) 0x02)
		: "cc", "memory"
	);
}

static inline uint16_t sys_get_tick_count(void) {
	uint16_t result;
	__asm volatile (
		"int $0x17"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x03)
		: "cc", "memory"
	);
	return result;
}

static inline void sys_sleep(void) {
	uint16_t result;
	__asm volatile (
		"int $0x17"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x04)
		: "cc", "memory"
	);
}

static inline void sys_set_sleep_time(uint16_t value) {
	uint16_t result;
	__asm volatile (
		"int $0x17"
		: "=a" (result)
		: "b" (value), "Rah" ((uint8_t) 0x05)
		: "cc", "memory"
	);
}

static inline uint16_t sys_get_sleep_time(void) {
	uint16_t result;
	__asm volatile (
		"int $0x17"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x06)
		: "cc", "memory"
	);
	return result;
}

static inline void sys_set_awake_key(uint16_t value) {
	uint16_t result;
	__asm volatile (
		"int $0x17"
		: "=a" (result)
		: "b" (value), "Rah" ((uint8_t) 0x07)
		: "cc", "memory"
	);
}

static inline uint16_t sys_get_awake_key(void) {
	uint16_t result;
	__asm volatile (
		"int $0x17"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x08)
		: "cc", "memory"
	);
	return result;
}

static inline void sys_set_keepalive_int(uint16_t value) {
	uint16_t result;
	__asm volatile (
		"int $0x17"
		: "=a" (result)
		: "b" (value), "Rah" ((uint8_t) 0x09)
		: "cc", "memory"
	);
}

void sys_get_ownerinfo(uint16_t size, void __far* data);

static inline void sys_set_remote(uint8_t value) {
	uint16_t result;
	__asm volatile (
		"int $0x17"
		: "=a" (result)
		: "a" ((uint16_t) (((0x0D) << 8) | (value & 0xFF)))
		: "cc", "memory"
	);
}

static inline uint8_t sys_get_remote(void) {
	uint16_t result;
	__asm volatile (
		"int $0x17"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x0E)
		: "cc", "memory"
	);
	return result;
}

static inline void* sys_alloc_iram(void* ptr, uint16_t size) {
	uint16_t result;
	__asm volatile (
		"int $0x17"
		: "=a" (result)
		: "b" (ptr), "c" (size), "Rah" ((uint8_t) 0x0F)
		: "cc", "memory"
	);
	return result;
}

static inline void sys_free_iram(void* ptr) {
	uint16_t result;
	__asm volatile (
		"int $0x17"
		: "=a" (result)
		: "b" (ptr), "Rah" ((uint8_t) 0x10)
		: "cc", "memory"
	);
}

static inline void* sys_get_my_iram(void) {
	uint16_t result;
	__asm volatile (
		"int $0x17"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x11)
		: "cc", "memory"
	);
	return result;
}

static inline uint16_t sys_get_version(void) {
	uint16_t result;
	__asm volatile (
		"int $0x17"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x12)
		: "cc", "memory"
	);
	return result;
}

static inline void sys_set_resume(uint16_t value) {
	uint16_t result;
	__asm volatile (
		"int $0x17"
		: "=a" (result)
		: "b" (value), "Rah" ((uint8_t) 0x14)
		: "cc", "memory"
	);
}

static inline uint16_t sys_get_resume(void) {
	uint16_t result;
	__asm volatile (
		"int $0x17"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x15)
		: "cc", "memory"
	);
	return result;
}

/* End auto-generated section */


#endif /* __LIBWW_SYS_SYSTEM_H__ */
