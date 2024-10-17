/**
 * Copyright (c) 2022 Adrian "asie" Siekierka
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source distribution.
*/

	.arch	i186
	.code16
	.intel_syntax noprefix

	.global wwc_font_set_colordata
wwc_font_set_colordata:
	push	si
	push	di
	push	ds
	push	es
	push	bp
	mov	bp, sp
	// ES:DI - destination pointer
	xor	bx, bx
	mov	es, bx
	mov	di, ax
	shl	di, 4
	add di, 0x4000
	// DS:SI - source pointer
#ifdef __IA16_CMODEL_IS_FAR_TEXT
	lds	si, [bp + 14]
#else
	lds	si, [bp + 12]
#endif
	// CX - length
	mov	cx, dx
	shl	cx, 4
	cld
	rep	movsw
	pop	bp
	pop	es
	pop	ds
	pop	di
	pop	si
	ret	0x4
