#include <sys/types.h>

#ifndef __LIBWW_SYS_LIBWWC_H__
#define __LIBWW_SYS_LIBWWC_H__

/* Begin auto-generated section */

/* Hardware architectures */
/* WonderSwan-compatible console */
#define HARDARCH_WS 0
/* WonderSwan Color-compatible console */
#define HARDARCH_WSC 1

/* Color modes */
/* 2bpp mono mode */
#define COLOR_MODE_GRAYSCALE 0x00
/* 2bpp color mode */
#define COLOR_MODE_4COLOR 0x80
/* 4bpp planar color mode */
#define COLOR_MODE_16COLOR 0xC0
/* 4bpp packed color mode */
#define COLOR_MODE_16PACKED 0xE0

uint8_t wwc_get_hardarch(void);

void wwc_set_color_mode(uint8_t mode);

uint8_t wwc_get_color_mode(void);

void wwc_palette_set_color(uint8_t index, uint8_t color, uint16_t rgb);

uint16_t wwc_palette_get_color(uint8_t index, uint8_t color);

void wwc_font_set_colordata(uint16_t start, uint16_t count, const void __far* data);

void wwc_font_get_colordata(uint16_t start, uint16_t count, void __far* data);

void wwc_clear_font(void);

void wwc_sys_get_ownerinfo(uint16_t size, void* data);

/* End auto-generated section */


#endif /* __LIBWW_SYS_LIBWWC_H__ */
