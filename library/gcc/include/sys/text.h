#include <sys/types.h>

#ifndef __LIBWW_SYS_TEXT_H__
#define __LIBWW_SYS_TEXT_H__

/* Begin auto-generated section */

/* text_put_numeric() flags */
/* Output in hexadecimal instead of decimal */
#define NUM_HEXA 0x01
/* Pad using spaces */
#define NUM_PADSPACE 0x00
/* Pad using zeroes */
#define NUM_PADZERO 0x02
/* Align to right */
#define NUM_ALIGN_RIGHT 0x00
/* Align to left */
#define NUM_ALIGN_LEFT 0x04
/* Number is signed instead of unsigned */
#define NUM_SIGNED 0x08
/* Output to buffer instead of text window */
#define NUM_STORE 0x80

/* Text modes */
/* ASCII */
#define TEXT_MODE_ANK 0
/* ASCII/Shift-JIS */
#define TEXT_MODE_ANK_SJIS 1
/* Shift-JIS */
#define TEXT_MODE_SJIS 2

/* Useful constants */
#define TEXT_SCREEN_WIDTH 28
#define TEXT_SCREEN_HEIGHT 18

/**
 * Initializes a text window with the following default settings:
 * - X, Y = 0, 0
 * - width, height = 28, 18
 * - base tile = 512 - font tile count (in ASCII mode)
 * - base tile = 512 - (width x height) (in Shift-JIS and mixed modes)
 */
static inline void text_screen_init(void) {
	uint16_t result;
	__asm volatile (
		"int $0x13"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x00)
		: "cc", "memory"
	);
}

/**
 * Initializes a text window on the configured screen.
 * This requires the following number of tiles, starting from the base:
 * - font tile count (in ASCII mode)
 * - width x height (in Shift-JIS and mixed modes)
 * @param x Starting X offset, in tiles.
 * @param y Starting Y offset, in tiles.
 * @param width Width of text window, in tiles.
 * @param height Height of text window, in tiles.
 * @param base Base tile index.
 */
static inline void text_window_init(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint16_t base) {
	uint16_t result;
	__asm volatile (
		"int $0x13"
		: "=a" (result)
		: "d" (base), "b" (((y << 8) | x)), "c" (((height << 8) | width)), "Rah" ((uint8_t) 0x01)
		: "cc", "memory"
	);
}

/**
 * Set text mode.
 */
static inline void text_set_mode(uint16_t value) {
	uint16_t result;
	__asm volatile (
		"int $0x13"
		: "=a" (result)
		: "b" (value), "Rah" ((uint8_t) 0x02)
		: "cc", "memory"
	);
}

/**
 * Get text mode.
 */
static inline uint16_t text_get_mode(void) {
	uint16_t result;
	__asm volatile (
		"int $0x13"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x03)
		: "cc", "memory"
	);
	return (uint16_t) result;
}

static inline void text_put_char(uint8_t x, uint8_t y, uint16_t ch) {
	uint16_t result;
	__asm volatile (
		"int $0x13"
		: "=a" (result)
		: "c" (ch), "b" (((y << 8) | x)), "Rah" ((uint8_t) 0x04)
		: "cc", "memory"
	);
}

/**
 * @return Number of characters displayed.
 */
uint16_t text_put_string(uint8_t x, uint8_t y, const char __far* str);

/**
 * @return Number of characters displayed.
 */
uint16_t text_put_substring(uint8_t x, uint8_t y, const char __far* str, uint16_t length);

/**
 * @return Number of characters displayed.
 */
static inline uint16_t text_put_numeric(uint8_t x, uint8_t y, uint8_t width, uint8_t flags, uint16_t value) {
	uint16_t result;
	__asm volatile (
		"int $0x13"
		: "=a" (result)
		: "d" (value), "b" (((y << 8) | x)), "c" (((flags << 8) | width)), "Rah" ((uint8_t) 0x07)
		: "cc", "memory"
	);
	return (uint16_t) result;
}

/**
 * @return Number of characters stored.
 */
uint16_t text_store_numeric(void __far* buffer, uint8_t width, uint8_t flags, uint16_t value);

static inline void text_fill_char(uint8_t x, uint8_t y, uint16_t length, uint16_t ch) {
	uint16_t result;
	__asm volatile (
		"int $0x13"
		: "=a" (result)
		: "c" (length), "d" (ch), "b" (((y << 8) | x)), "Rah" ((uint8_t) 0x08)
		: "cc", "memory"
	);
}

/**
 * Set the palette used by printed text.
 * @param index Palette index.
 */
static inline void text_set_palette(uint16_t index) {
	uint16_t result;
	__asm volatile (
		"int $0x13"
		: "=a" (result)
		: "b" (index), "Rah" ((uint8_t) 0x09)
		: "cc", "memory"
	);
}

/**
 * Get the palette used by printed text.
 * @return Palette index.
 */
static inline uint16_t text_get_palette(void) {
	uint16_t result;
	__asm volatile (
		"int $0x13"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x0A)
		: "cc", "memory"
	);
	return (uint16_t) result;
}

/**
 * @param start Starting character code
 * @param depth 0 = 1BPP, 1 = 2BPP
 * @param count Number of characters (tiles)
 * @param data Input buffer containing font data
 */
void text_set_ank_font(uint8_t start, uint8_t depth, uint16_t count, const void __far* data);

/**
 * @param handler Shift-JIS font handler
 */
void text_set_sjis_font(void __far* handler);

/**
 * @param ch Character code
 * @param data Output buffer for font data
 * @return 0x0000 on success, 0x8000 on failure.
 */
uint16_t text_get_fontdata(uint16_t ch, void __far* data);

/**
 * @param id Screen ID
 */
static inline void text_set_screen(uint8_t id) {
	uint16_t result;
	__asm volatile (
		"int $0x13"
		: "=a" (result)
		: "a" ((uint16_t) (((0x0E) << 8) | (id & 0xFF)))
		: "cc", "memory"
	);
}

/**
 * @return Screen ID
 */
static inline uint8_t text_get_screen(void) {
	uint16_t result;
	__asm volatile (
		"int $0x13"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x0F)
		: "cc", "memory"
	);
	return (uint8_t) result;
}

/**
 * @param value Cursor status (0 - disabled, 1 - enabled)
 */
static inline void cursor_display(uint8_t value) {
	uint16_t result;
	__asm volatile (
		"int $0x13"
		: "=a" (result)
		: "a" ((uint16_t) (((0x10) << 8) | (value & 0xFF)))
		: "cc", "memory"
	);
}

/**
 * @return Cursor status (bit 0 - enabled?, bit 1 - currently visible?)
 */
static inline uint8_t cursor_status(void) {
	uint16_t result;
	__asm volatile (
		"int $0x13"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x11)
		: "cc", "memory"
	);
	return (uint8_t) result;
}

static inline void cursor_set_location(uint8_t x, uint8_t y, uint8_t width, uint8_t height) {
	uint16_t result;
	__asm volatile (
		"int $0x13"
		: "=a" (result)
		: "b" (((y << 8) | x)), "c" (((height << 8) | width)), "Rah" ((uint8_t) 0x12)
		: "cc", "memory"
	);
}

static inline uint32_t cursor_get_location(void) {
	uint32_t result;
	__asm volatile (
		"int $0x13"
		: "=A" (result)
		: "Rah" ((uint8_t) 0x13)
		: "cc", "memory"
	);
	return (uint32_t) result;
}

/**
 * @param palette Palette index used by cursor area when visible
 * @param rate Blinking rate, in frames; 0 - always visible
 */
static inline void cursor_set_type(uint8_t palette, uint8_t rate) {
	uint16_t result;
	__asm volatile (
		"int $0x13"
		: "=a" (result)
		: "b" (palette), "c" (rate), "Rah" ((uint8_t) 0x14)
		: "cc", "memory"
	);
}

static inline uint16_t cursor_get_type(void) {
	uint16_t result;
	__asm volatile (
		"int $0x13"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x15)
		: "cc", "memory"
	);
	return (uint16_t) result;
}

/* End auto-generated section */


#endif /* __LIBWW_SYS_TEXT_H__ */
