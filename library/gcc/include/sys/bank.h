#include <sys/types.h>

#ifndef __LIBWW_SYS_BANK_H__
#define __LIBWW_SYS_BANK_H__

/* Begin auto-generated section */

/* Bank region names */
#define BANK_SRAM 0
#define BANK_ROM0 1
#define BANK_ROM1 2

/* SRAM banks */
/* RAM file storage */
#define BANK_SOFTFS 0
#define BANK_USERDS1 1
#define BANK_USERDS0 2
#define BANK_OSWORK 3

/* bank_*_map utility wrappers */
#define sram_get_map() bank_get_map(BANK_SRAM)
#define sram_set_map(bank_id) bank_get_map(BANK_SRAM, bank_id)
#define rom0_get_map() bank_get_map(BANK_ROM0)
#define rom0_set_map(bank_id) bank_get_map(BANK_ROM0, bank_id)
#define rom1_get_map() bank_get_map(BANK_ROM1)
#define rom1_set_map(bank_id) bank_get_map(BANK_ROM1, bank_id)

/**
 * @param bank_type Bank region
 * @param bank Number of bank to map to region
 */
static inline void bank_set_map(uint16_t bank_type, uint16_t bank) {
	uint16_t result;
	__asm volatile (
		"int $0x18"
		: "=a" (result)
		: "b" (bank_type), "c" (bank), "Rah" ((uint8_t) 0x00)
		: "cc", "memory"
	);
}

/**
 * @param bank_type Bank region
 * @return Number of bank mapped to region
 */
static inline uint16_t bank_get_map(uint16_t bank_type) {
	uint16_t result;
	__asm volatile (
		"int $0x18"
		: "=a" (result)
		: "b" (bank_type), "Rah" ((uint8_t) 0x01)
		: "cc", "memory"
	);
	return (uint16_t) result;
}

/**
 * @param bank_id Bank ID
 * @param offset Offset within bank
 * @return Byte read
 */
static inline uint8_t bank_read_byte(uint16_t bank_id, uint16_t offset) {
	uint16_t result;
	__asm volatile (
		"int $0x18"
		: "=a" (result)
		: "b" (bank_id), "d" (offset), "Rah" ((uint8_t) 0x02)
		: "cc", "memory"
	);
	return (uint8_t) result;
}

/**
 * @param bank_id Bank ID
 * @param offset Offset within bank
 * @param value Byte to write
 */
static inline void bank_write_byte(uint16_t bank_id, uint16_t offset, uint8_t value) {
	uint16_t result;
	__asm volatile (
		"int $0x18"
		: "=a" (result)
		: "b" (bank_id), "d" (offset), "c" (value), "Rah" ((uint8_t) 0x03)
		: "cc", "memory"
	);
}

/**
 * @param bank_id Bank ID
 * @param offset Offset within bank
 * @return Word read
 */
static inline uint8_t bank_read_word(uint16_t bank_id, uint16_t offset) {
	uint16_t result;
	__asm volatile (
		"int $0x18"
		: "=a" (result)
		: "b" (bank_id), "d" (offset), "Rah" ((uint8_t) 0x04)
		: "cc", "memory"
	);
	return (uint8_t) result;
}

/**
 * @param bank_id Bank ID
 * @param offset Offset within bank
 * @param value Word to write
 */
static inline void bank_write_word(uint16_t bank_id, uint16_t offset, uint16_t value) {
	uint16_t result;
	__asm volatile (
		"int $0x18"
		: "=a" (result)
		: "b" (bank_id), "d" (offset), "c" (value), "Rah" ((uint8_t) 0x05)
		: "cc", "memory"
	);
}

/**
 * @param bank_id Bank ID
 * @param offset Offset within bank
 * @param data Output buffer
 * @param length Length of data to read
 */
void bank_read_block(uint16_t bank_id, uint16_t offset, void __far* data, uint16_t length);

/**
 * @param bank_id Bank ID
 * @param offset Offset within bank
 * @param data Input buffer
 * @param length Length of data to write
 */
void bank_write_block(uint16_t bank_id, uint16_t offset, const void __far* data, uint16_t length);

/**
 * @param bank_id Bank ID
 * @param offset Offset within bank
 * @param length Length of data to write
 * @param value Byte to fill
 */
static inline void bank_fill_block(uint16_t bank_id, uint16_t offset, uint16_t length, uint8_t value) {
	uint16_t result;
	__asm volatile (
		"int $0x18"
		: "=a" (result)
		: "a" ((uint16_t) (((0x08) << 8) | (value & 0xFF))), "b" (bank_id), "d" (offset), "c" (length)
		: "cc", "memory"
	);
}

/**
 * @param bank_id Bank ID
 */
static inline void bank_erase_flash(uint16_t bank_id) {
	uint16_t result;
	__asm volatile (
		"int $0x18"
		: "=a" (result)
		: "b" (bank_id), "Rah" ((uint8_t) 0x09)
		: "cc", "memory"
	);
}

/* End auto-generated section */


#endif /* __LIBWW_SYS_BANK_H__ */
