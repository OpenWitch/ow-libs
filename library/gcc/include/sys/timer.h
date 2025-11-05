#include <sys/types.h>

#ifndef __LIBWW_SYS_TIMER_H__
#define __LIBWW_SYS_TIMER_H__

/* Begin auto-generated section */

/* RTC fields */
#define RTC_YEAR 0
#define RTC_MONTH 1
#define RTC_DATE 2
#define RTC_DAY_OF_WEEK 3
#define RTC_HOUR 4
#define RTC_MIN 5
#define RTC_SEC 6

/* Timers */
#define TIMER_HBLANK 0
#define TIMER_VBLANK 1

/* Timer reload modes */
#define TIMER_ONESHOT 0
#define TIMER_AUTOPRESET 1

#define rtc_set_year(value) rtc_set_datetime(RTC_YEAR, value)
#define rtc_set_month(value) rtc_set_datetime(RTC_MONTH, value)
#define rtc_set_date(value) rtc_set_datetime(RTC_DATE, value)
#define rtc_set_day_of_week(value) rtc_set_datetime(RTC_DAY_OF_WEEK, value)
#define rtc_set_hour(value) rtc_set_datetime(RTC_HOUR, value)
#define rtc_set_minute(value) rtc_set_datetime(RTC_MIN, value)
#define rtc_set_second(value) rtc_set_datetime(RTC_SEC, value)

#define rtc_get_year() rtc_get_datetime(RTC_YEAR)
#define rtc_get_month() rtc_get_datetime(RTC_MONTH)
#define rtc_get_date() rtc_get_datetime(RTC_DATE)
#define rtc_get_day_of_week() rtc_get_datetime(RTC_DAY_OF_WEEK)
#define rtc_get_hour() rtc_get_datetime(RTC_HOUR)
#define rtc_get_minute() rtc_get_datetime(RTC_MIN)
#define rtc_get_second() rtc_get_datetime(RTC_SEC)

static inline void rtc_reset(void) {
	uint16_t result;
	__asm volatile (
		"int $0x16"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x00)
		: "cc", "memory"
	);
}

static inline void rtc_set_datetime(uint16_t field, uint16_t value) {
	uint16_t result;
	__asm volatile (
		"int $0x16"
		: "=a" (result)
		: "b" (field), "c" (value), "Rah" ((uint8_t) 0x01)
		: "cc", "memory"
	);
}

static inline uint16_t rtc_get_datetime(uint16_t field) {
	uint16_t result;
	__asm volatile (
		"int $0x16"
		: "=a" (result)
		: "b" (field), "Rah" ((uint8_t) 0x02)
		: "cc", "memory"
	);
	return (uint16_t) result;
}

void rtc_set_datetime_struct(const datetime_t __far* value);

void rtc_get_datetime_struct(datetime_t __far* value);

static inline void rtc_enable_alarm(uint8_t hour, uint8_t minute) {
	uint16_t result;
	__asm volatile (
		"int $0x16"
		: "=a" (result)
		: "b" (((minute << 8) | hour)), "Rah" ((uint8_t) 0x05)
		: "cc", "memory"
	);
}

static inline void rtc_disable_alarm(void) {
	uint16_t result;
	__asm volatile (
		"int $0x16"
		: "=a" (result)
		: "Rah" ((uint8_t) 0x06)
		: "cc", "memory"
	);
}

static inline void timer_enable(uint8_t type, uint16_t reload, uint16_t count) {
	uint16_t result;
	__asm volatile (
		"int $0x16"
		: "=a" (result)
		: "a" ((uint16_t) (((0x07) << 8) | (type & 0xFF))), "b" (reload), "c" (count)
		: "cc", "memory"
	);
}

static inline void timer_disable(uint8_t type) {
	uint16_t result;
	__asm volatile (
		"int $0x16"
		: "=a" (result)
		: "a" ((uint16_t) (((0x08) << 8) | (type & 0xFF)))
		: "cc", "memory"
	);
}

static inline uint16_t timer_get_count(uint8_t type) {
	uint16_t result;
	__asm volatile (
		"int $0x16"
		: "=a" (result)
		: "a" ((uint16_t) (((0x09) << 8) | (type & 0xFF)))
		: "cc", "memory"
	);
	return (uint16_t) result;
}

/* End auto-generated section */


#endif /* __LIBWW_SYS_TIMER_H__ */
