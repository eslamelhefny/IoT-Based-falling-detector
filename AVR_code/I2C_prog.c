/*
 * I2C_prog.c
 *
 *  Created on: Feb 9, 2019
 *      Author: Mohamed Magdy
 */
#include"../STD_TYPES.h"
#include"../BIT_math.h"
#include "I2C_int.h"
#include "I2C_reg.h"

void I2C_vidInit(void)
{
	/* Set prescaler to 1 */
	CLEAR_BIT(TWSR,TWPS0);
	CLEAR_BIT(TWSR,TWPS1);

	/* Set clock frequency to 250K at clock 12M */
	TWBR = 16;

	/* Set slave address */
	TWAR = 6;

	/* Enable TWI */
	SET_BIT(TWCR,TWEN);
}

void I2C_vidSendStart(void)
{
	/* Clear interrupt flag */
	/* Set Start condition bit */
	/* Enable to TWI */
	TWCR = (1<<TWSTA) | (1<<TWINT) | (1<<TWEN);
	/* Wait till TWINT flag is set */
	while(GET_BIT(TWCR,TWINT) == 0);
}

void I2C_vidSendStop(void)
{
	/* Clear interrupt flag */
	/* Set Stop condition bit */
	/* Enable to TWI */
	TWCR = (1<<TWSTO) | (1<<TWINT) | (1<<TWEN);
}

void I2C_vidSendSLA(u8 u8SlaveAdd)
{
	/* Set Slave address +operation to data reg */
	TWDR = u8SlaveAdd ;
	/* Clear interrupt flag */
	/* Enable to TWI */
	TWCR = (1<<TWINT) | (1<<TWEN);
	/* Wait till TWINT flag is set */
	while(GET_BIT(TWCR,TWINT) == 0);
}

void I2C_vidSendData(u8 u8SendData)
{
	/* Set Slave address +operation to data reg */
	TWDR = u8SendData;
	/* Clear interrupt flag */
	/* Enable to TWI */
	TWCR = (1<<TWINT) | (1<<TWEN);
	/* Wait till TWINT flag is set */
	while(GET_BIT(TWCR,TWINT) == 0);
}

u8 I2C_u8CheckStatus(u8 u8Status)
{
	if((TWSR & TWS_MASK) == u8Status)
	{
		return I2C_OK;
	}
	else
	{
		return I2C_NOK;
	}
}

u8 I2C_u8ReceiveWithNoAck(void)
{
	TWCR = (1<< TWINT) | (1<<TWEN);
	/* Wait till TWINT flag is set */
	while(GET_BIT(TWCR,TWINT) == 0);
	return TWDR;
}

u8 I2C_u8ReceiveWithAck(void)
{
	TWCR = (1<< TWINT) | (1<<TWEN) | (1<<TWEA) ;
	/* Wait till TWINT flag is set */
	while(GET_BIT(TWCR,TWINT) == 0);
	return TWDR;

}
