/*
 * i2c.c
 *
 * Created: 26-Oct-14 2:47:01 PM
 *  Author: Shekhar
 */ 

#include "i2c.h"

/*
 * 
 *
 * 
 * 
 *
 */
char i2c_start(char speed_in_KHz)
{
	// Select I2C Speed
	
	
	// Configure I2C in Polling
	TWCR |= (1 << TWINT) | (1 << TWEN) | (1 << TWEA) | (1 << TWSTA);	//Enable I2C,Enable ack
	TWCR &= ~(1 << TWSTO);
	
	// Wait for the Start condition to be transmitted
	while (!(TWCR & (1<<TWINT)));
	
	// Return the STATUS
	if(I2C_STATUS == TW_START)
		return 1;
	else
		return 0;
}

/*
 * 
 *
 * 
 * 
 *
 */
char i2c_stop()
{
	// Stop I2C
	TWCR |= (1 << TWINT);
	TWCR &= ~(1 << TWSTA);
	TWCR |= (1 << TWSTO) | (1 << TWEN);
	
	if(I2C_STATUS == TW_SR_STOP)
		return 1;
	else
		return 0;
}

/*
 * 
 *
 * 
 * 
 *
 */
char i2c_restart()
{
	TWCR |= (1 << TWINT) | (1 << TWSTA);
	TWCR &= ~(1 << TWSTO);
	TWCR |= (1 << TWEN);
	
	// Wait for the restart condition to be transmitted
	while (!(TWCR & (1<<TWINT)));
	
	if(I2C_STATUS == TW_REP_START)
		return 1;
	else
		return 0;
}

/*
 * 
 *
 * 
 * 
 *
 */
char i2c_write(char data_to_be_written)
{
	TWDR = data_to_be_written;
	TWINT_FLAG_CLR;
	
	// Wait for the Data to be transmitted
	while (!(TWCR & (1<<TWINT)));
	
	// Read TWSR and check whether the ack received
	if((I2C_STATUS == TW_MT_SLA_ACK) || (I2C_STATUS == TW_MT_DATA_ACK) || (I2C_STATUS == TW_MR_SLA_ACK))
		return 1;
	else
		return 0;
}

/*
 * 
 *
 * 
 * 
 *
 */
void i2c_read(char *data)
{	
	TWINT_FLAG_CLR;
	while (!(TWCR & (1<<TWINT)));
	*data = TWDR;
}