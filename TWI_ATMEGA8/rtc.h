/*
 * rtc.h
 *
 * For DS1307 RTC
 * Created: 26-Oct-14 10:28:57 PM
 *  Author: H
 */ 


#ifndef RTC_H_
#define RTC_H_

#define uchar unsigned char

#include "i2c.h"

#define RTC_WRITE_ADD	0xD0
#define RTC_READ_ADD	0xD1

char rtc_write(uchar address,uchar data);
char rtc_read(uchar address);

#endif /* RTC_H_ */