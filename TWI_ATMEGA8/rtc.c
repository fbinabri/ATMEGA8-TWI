/*
 * rtc.c
 *
 * Created: 26-Oct-14 10:29:22 PM
 *  Author: H
 */ 

#include "rtc.h"
 
char rtc_write(uchar address,uchar data)
{
	char ret = 0;
	if(i2c_start(0))
	if(i2c_write(RTC_WRITE_ADD))
	if(i2c_write(address))
	if(i2c_write(data))
	if(i2c_stop())
		ret = 1;
	return ret;	
}

char rtc_read(uchar address)
{
	char data = 0;
	if(i2c_start(0))
	if(i2c_write(RTC_WRITE_ADD))
	if(i2c_write(address))
	if(i2c_restart())
	if(i2c_write(RTC_READ_ADD))
	i2c_read(&data);
	i2c_stop();
	return data;
}