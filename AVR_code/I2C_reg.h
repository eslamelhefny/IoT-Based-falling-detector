/*
 * I2C_reg.h
 *
 *  Created on: Feb 9, 2019
 *      Author: Mohamed Magdy
 */

#ifndef I2C_REG_H_
#define I2C_REG_H_

#define TWBR   (*(volatile u8*)0x20)
#define TWSR   (*(volatile u8*)0x21)
#define TWAR   (*(volatile u8*)0x22)
#define TWDR   (*(volatile u8*)0x23)
#define TWCR   (*(volatile u8*)0x56)


/* TWCR Register */
#define TWINT 7
#define TWEA  6
#define TWSTA 5
#define TWSTO 4
#define TWWC  3
#define TWEN  2

/* TWSR Register */
#define TWPS1  1
#define TWPS0  0
#define TWS_MASK  0xF8

#endif /* I2C_REG_H_ */
