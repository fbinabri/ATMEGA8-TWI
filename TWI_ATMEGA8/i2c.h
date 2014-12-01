/*
 * i2c.h
 *
 * Created: 26-Oct-14 2:46:27 PM
 *  Author: Shekhar
 */ 

#ifndef I2C_H_
#define I2C_H_

#include <avr/io.h>
#include <util/twi.h>

#define I2C_STATUS			(TWSR & 0xF8)
#define TWINT_FLAG_CLR		TWCR = (1 << TWINT) | (1 << TWEN)

char i2c_start(char speed_in_KHz);
char i2c_stop();
char i2c_restart();
char i2c_write(char data_to_be_written);
void i2c_read(char *data);

#endif /* I2C_H_ */