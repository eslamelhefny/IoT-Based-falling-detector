/*
 * I2C_int.h
 *
 *  Created on: Feb 9, 2019
 *      Author: Mohamed Magdy
 */

#ifndef I2C_INT_H_
#define I2C_INT_H_

#define I2C_READ  0x01
#define I2C_WRITE 0x00

#define I2C_OK    0x00
#define I2C_NOK   0x01

/* Common Status code */
#define I2C_START            0x08
#define I2C_REP_START        0x10

/* Master transmitter Status Code */
#define I2C_MT_SLA_ACK       0x18
#define I2C_MT_SLA_NOT_ACK   0x20
#define I2C_MT_DATA_ACK      0x28
#define I2C_MT_DATA_NOT_ACK  0x30
#define I2C_MT_ARB_LOST      0x38

/* Master Receiver Status Code    */
#define I2C_MR_ARB_LOST      0x38
#define I2C_MR_SLA_ACK       0x40
#define I2C_MR_SLA_NOT_ACK   0x48
#define I2C_MR_DATA_ACK      0x50
#define I2C_MR_DATA_NOT_ACK  0x58


void I2C_vidInit(void);
void I2C_vidSendStart(void);
void I2C_vidSendStop(void);
void I2C_vidSendSLA(u8 u8SlaveAdd);
void I2C_vidSendData(u8 u8SendData);

u8 I2C_u8CheckStatus(u8 u8Status);
u8 I2C_u8ReceiveWithNoAck(void);
u8 I2C_u8ReceiveWithAck(void);

#endif /* I2C_INT_H_ */
