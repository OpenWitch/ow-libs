#include <sys/types.h>

#ifndef __LIBWW_SYS_SOUND_H__
#define __LIBWW_SYS_SOUND_H__

/* Begin auto-generated section */

static inline void sound_init(void) {
	uint16_t result;
	__asm volatile (
		"int $0x15"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x00)
		: "cc", "memory"
	);
}

static inline void sound_set_channel(uint16_t value) {
	uint16_t result;
	__asm volatile (
		"int $0x15"
		: "=a" (result)
		: "b" (value), "Rah" ((uint8_t) 0x01)
		: "cc", "memory"
	);
}

static inline uint16_t sound_get_channel(void) {
	uint16_t result;
	__asm volatile (
		"int $0x15"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x02)
		: "cc", "memory"
	);
	return result;
}

static inline void sound_set_output(uint16_t value) {
	uint16_t result;
	__asm volatile (
		"int $0x15"
		: "=a" (result)
		: "b" (value), "Rah" ((uint8_t) 0x03)
		: "cc", "memory"
	);
}

static inline uint16_t sound_get_output(void) {
	uint16_t result;
	__asm volatile (
		"int $0x15"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x04)
		: "cc", "memory"
	);
	return result;
}

void sound_set_wave(uint8_t channel, const void __far* data);

static inline void sound_set_pitch(uint16_t channel, uint16_t value) {
	uint16_t result;
	__asm volatile (
		"int $0x15"
		: "=a" (result)
		: "a" ((uint16_t) (((0x06) << 8) | (channel & 0xFF))), "b" (value)
		: "cc", "memory"
	);
}

static inline uint16_t sound_get_pitch(uint16_t channel) {
	uint16_t result;
	__asm volatile (
		"int $0x15"
		: "=a" (result)
		: "a" ((uint16_t) (((0x07) << 8) | (channel & 0xFF)))
		: "cc", "memory"
	);
	return result;
}

static inline void sound_set_volume(uint16_t channel, uint16_t value) {
	uint16_t result;
	__asm volatile (
		"int $0x15"
		: "=a" (result)
		: "a" ((uint16_t) (((0x08) << 8) | (channel & 0xFF))), "b" (value)
		: "cc", "memory"
	);
}

static inline uint16_t sound_get_volume(uint16_t channel) {
	uint16_t result;
	__asm volatile (
		"int $0x15"
		: "=a" (result)
		: "a" ((uint16_t) (((0x09) << 8) | (channel & 0xFF)))
		: "cc", "memory"
	);
	return result;
}

static inline void sound_set_sweep(uint8_t sweep, uint8_t step_time) {
	uint16_t result;
	__asm volatile (
		"int $0x15"
		: "=a" (result)
		: "b" (sweep), "c" (step_time), "Rah" ((uint8_t) 0x0A)
		: "cc", "memory"
	);
}

static inline uint16_t sound_get_sweep(void) {
	uint16_t result;
	__asm volatile (
		"int $0x15"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x0B)
		: "cc", "memory"
	);
	return result;
}

static inline void sound_set_noise(uint16_t value) {
	uint16_t result;
	__asm volatile (
		"int $0x15"
		: "=a" (result)
		: "b" (value), "Rah" ((uint8_t) 0x0C)
		: "cc", "memory"
	);
}

static inline uint16_t sound_get_noise(void) {
	uint16_t result;
	__asm volatile (
		"int $0x15"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x0D)
		: "cc", "memory"
	);
	return result;
}

static inline uint16_t sound_get_random(void) {
	uint16_t result;
	__asm volatile (
		"int $0x15"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x0E)
		: "cc", "memory"
	);
	return result;
}


/* 0% volume (muted) */
#define SOUND_VOICE_MUTE 0
/* 50% volume */
#define SOUND_VOICE_HALF 2
/* 100% volume */
#define SOUND_VOICE_FULL 3

void sound_set_voice_volume(uint8_t left, uint8_t right);

/* End auto-generated section */


#endif /* __LIBWW_SYS_SOUND_H__ */
