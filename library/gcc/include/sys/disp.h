#include <sys/types.h>

#ifndef __LIBWW_SYS_DISP_H__
#define __LIBWW_SYS_DISP_H__

/* Begin auto-generated section */

/* display_control() flags */
/* Enable screen 1 layer */
#define DCM_SCR1 0x01
/* Enable screen 2 layer */
#define DCM_SCR2 0x02
/* Enable sprite layer */
#define DCM_SPR 0x04
/* Enable sprite layer window */
#define DCM_SPR_WIN 0x08
/* Enable screen 2 layer window, display inside window */
#define DCM_SCR2_WIN_INSIDE 0x20
/* Enable screen 2 layer window, display outside window */
#define DCM_SCR2_WIN_OUTSIDE 0x30
/* Border color mask (mono mode) */
#define DCM_BORDER_COLOR 0x0700

/* Screen IDs */
#define SCREEN1 0
#define SCREEN2 1

/* Tile attribute flags */
/* Tile index mask */
#define CFM_FONT 0x01FF
/* Palette shift */
#define CFSFT_PALETTE 9
/* Tile palette mask */
#define CFM_SCR_PALETTE 0x1E00
/* Sprite palette mask */
#define CFM_SPR_PALETTE 0x0E00
/* Display sprite outside window area */
#define CFM_SPRWIN_CLIP 0x1000
/* Display sprite in front of screen 2 */
#define CFM_SPR_UPPER 0x2000
/* Flip horizontally */
#define CFM_FLIP_H 0x4000
/* Flip vertically */
#define CFM_FLIP_V 0x8000

/* LCD segment flags */
/* Sleep */
#define LCDSEG_SLEEP 0x01
/* Vertical orientation */
#define LCDSEG_VERTICAL 0x02
/* Horizontal orientation */
#define LCDSEG_HORIZONTAL 0x04
/* Aux 1 */
#define LCDSEG_AUX1 0x08
/* Aux 2 */
#define LCDSEG_AUX2 0x10
/* Aux 3 */
#define LCDSEG_AUX3 0x20

/* LCD sleep modes */
/* Sleep on (display disabled) */
#define LCD_SLEEP_ON 0
/* Sleep off (display enabled) */
#define LCD_SLEEP_OFF 1

#define lcd_on() lcd_set_sleep(LCD_SLEEP_OFF)
#define lcd_off() lcd_set_sleep(LCD_SLEEP_ON)

/* Useful constants */
#define LCD_PIXEL_WIDTH 224
#define LCD_PIXEL_HEIGHT 144
#define SCREEN_PIXEL_WIDTH 256
#define SCREEN_PIXEL_HEIGHT 256
#define SCREEN_CHAR_WIDTH 32
#define SCREEN_CHAR_HEIGHT 32

static inline void display_control(uint16_t value) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "b" (value), "Rah" ((uint8_t) 0x00)
		: "cc", "memory"
	);
}

static inline uint16_t display_status(void) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x01)
		: "cc", "memory"
	);
	return result;
}

void font_set_monodata(uint16_t start, uint16_t count, const void __far* data);

void font_set_colordata(uint16_t start, uint16_t count, const void __far* data);

void font_get_data(uint16_t start, uint16_t count, void __far* data);

static inline void font_set_color(uint16_t value) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "b" (value), "Rah" ((uint8_t) 0x05)
		: "cc", "memory"
	);
}

static inline uint16_t font_get_color(void) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x06)
		: "cc", "memory"
	);
	return result;
}

void screen_set_char(uint8_t screen_id, uint8_t x, uint8_t y, uint8_t width, uint8_t height, const void __far* tiles);

void screen_get_char(uint8_t screen_id, uint8_t x, uint8_t y, uint8_t width, uint8_t height, void __far* tiles);

static inline uint16_t screen_get_char1(uint8_t screen_id, uint8_t x, uint8_t y) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "a" ((uint16_t) (((0x08) << 8) | (screen_id & 0xFF))), "b" (((y << 8) | x)), "c" ((uint16_t) 0)
		: "cc", "memory"
	);
	return result;
}

static inline void screen_fill_char(uint8_t screen_id, uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint16_t tile) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "a" ((uint16_t) (((0x09) << 8) | (screen_id & 0xFF))), "d" (tile), "b" (((y << 8) | x)), "c" (((height << 8) | width))
		: "cc", "memory"
	);
}

static inline void screen_fill_attr(uint8_t screen_id, uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint16_t tile, uint16_t mask) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "a" ((uint16_t) (((0x0A) << 8) | (screen_id & 0xFF))), "d" (tile), "S" (mask), "b" (((y << 8) | x)), "c" (((height << 8) | width))
		: "cc", "memory"
	);
}

static inline void sprite_set_range(uint16_t first, uint16_t count) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "b" (first), "c" (count), "Rah" ((uint8_t) 0x0B)
		: "cc", "memory"
	);
}

static inline void sprite_set_char(uint16_t id, uint16_t tile) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "b" (id), "c" (tile), "Rah" ((uint8_t) 0x0C)
		: "cc", "memory"
	);
}

static inline uint16_t sprite_get_char(uint16_t id) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "b" (id), "Rah" ((uint8_t) 0x0D)
		: "cc", "memory"
	);
	return result;
}

static inline void sprite_set_location(uint16_t id, uint8_t x, uint8_t y) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "b" (id), "d" (((y << 8) | x)), "Rah" ((uint8_t) 0x0E)
		: "cc", "memory"
	);
}

static inline uint16_t sprite_get_location(uint16_t id) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "b" (id), "Rah" ((uint8_t) 0x0F)
		: "cc", "memory"
	);
	return result;
}

static inline void sprite_set_char_location(uint16_t id, uint16_t tile, uint8_t x, uint8_t y) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "b" (id), "c" (tile), "d" (((y << 8) | x)), "Rah" ((uint8_t) 0x10)
		: "cc", "memory"
	);
}

static inline uint32_t sprite_get_char_location(uint16_t id) {
	uint32_t result;
	__asm volatile (
		"int $0x12"
		: "=A" (result)
		: "b" (id), "Rah" ((uint8_t) 0x11)
		: "cc", "memory"
	);
	return result;
}

void sprite_set_data(uint16_t first, uint16_t count, const void __far* data);

static inline void screen_set_scroll(uint8_t id, uint8_t x, uint8_t y) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "a" ((uint16_t) (((0x13) << 8) | (id & 0xFF))), "b" (((y << 8) | x))
		: "cc", "memory"
	);
}

static inline uint16_t screen_get_scroll(uint8_t id) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "a" ((uint16_t) (((0x14) << 8) | (id & 0xFF)))
		: "cc", "memory"
	);
	return result;
}

static inline void screen2_set_window(uint8_t x, uint8_t y, uint8_t width, uint8_t height) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "b" (((y << 8) | x)), "c" (((height << 8) | width)), "Rah" ((uint8_t) 0x15)
		: "cc", "memory"
	);
}

static inline uint32_t screen2_get_window(void) {
	uint32_t result;
	__asm volatile (
		"int $0x12"
		: "=A" (result)
		: "Rah" ((uint8_t) 0x16)
		: "cc", "memory"
	);
	return result;
}

static inline void sprite_set_window(uint8_t x, uint8_t y, uint8_t width, uint8_t height) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "b" (((y << 8) | x)), "c" (((height << 8) | width)), "Rah" ((uint8_t) 0x17)
		: "cc", "memory"
	);
}

static inline uint32_t sprite_get_window(void) {
	uint32_t result;
	__asm volatile (
		"int $0x12"
		: "=A" (result)
		: "Rah" ((uint8_t) 0x18)
		: "cc", "memory"
	);
	return result;
}

static inline void palette_set_color(uint16_t index, uint16_t colors) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "b" (index), "c" (colors), "Rah" ((uint8_t) 0x19)
		: "cc", "memory"
	);
}

static inline uint16_t palette_get_color(uint16_t index) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "b" (index), "Rah" ((uint8_t) 0x1A)
		: "cc", "memory"
	);
	return result;
}

static inline void lcd_set_color(uint16_t low, uint16_t high) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "b" (low), "c" (high), "Rah" ((uint8_t) 0x1B)
		: "cc", "memory"
	);
}

static inline uint32_t lcd_get_color(void) {
	uint32_t result;
	__asm volatile (
		"int $0x12"
		: "=A" (result)
		: "Rah" ((uint8_t) 0x1C)
		: "cc", "memory"
	);
	return result;
}

static inline void lcd_set_segments(uint16_t flags) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "b" (flags), "Rah" ((uint8_t) 0x1D)
		: "cc", "memory"
	);
}

static inline uint16_t lcd_get_segments(void) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x1E)
		: "cc", "memory"
	);
	return result;
}

static inline void lcd_set_sleep(uint16_t flags) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "b" (flags), "Rah" ((uint8_t) 0x1F)
		: "cc", "memory"
	);
}

static inline uint16_t lcd_get_sleep(void) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x20)
		: "cc", "memory"
	);
	return result;
}

/**
 * @param offset IRAM address, shifted right by 11
 */
static inline void screen_set_vram(uint8_t id, uint8_t offset) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "a" ((uint16_t) (((0x21) << 8) | (id & 0xFF))), "b" (offset)
		: "cc", "memory"
	);
}

/**
 * @param offset IRAM address, shifted right by 9
 */
static inline void sprite_set_vram(uint8_t offset) {
	uint16_t result;
	__asm volatile (
		"int $0x12"
		: "=a" (result)
		: "b" (offset), "Rah" ((uint8_t) 0x22)
		: "cc", "memory"
	);
}

/* End auto-generated section */


#endif /* __LIBWW_SYS_DISP_H__ */
