///*
// * MPU_6050_pprog.c
// *
// *  Created on: Apr 22, 2020
// *      Author: IoT Scientest
// */
//#include "avr/delay.h"
//#include "../STD_TYPES.h"
//#include "MPU_6050_int.h"
//#include "I2C_int.h"
//void MPU_u8Init(void)
//{
//	I2C_vidSendStart();
//	I2C_vidSendSLA(MPU_SLA,I2C_WRITE);
//	I2C_vidSendData(MPU_SMPLRT_DIV);
//	I2C_vidSendData(0x07);/*1 KH Sample Rate*/
//	I2C_vidSendStop();
//
//
//	I2C_vidSendStart();
//	I2C_vidSendSLA(MPU_SLA,I2C_WRITE);
//	I2C_vidSendData(MPU_PWR_MGMT_1);
//	I2C_vidSendData(0x01);
//	I2C_vidSendStop();
//
//	I2C_vidSendStart();
//	I2C_vidSendSLA(MPU_SLA,I2C_WRITE);
//	I2C_vidSendData(MPU_CONFIG);
//	I2C_vidSendData(0x00);
//	I2C_vidSendStop();
//
//
//	I2C_vidSendStart();
//	I2C_vidSendSLA(MPU_SLA,I2C_WRITE);
//	I2C_vidSendData(MPU_GYRO_CONFIG);
//	I2C_vidSendData(0x18);
//	I2C_vidSendStop();
//
//
//
//	I2C_vidSendStart();
//	I2C_vidSendSLA(MPU_SLA,I2C_WRITE);
//	I2C_vidSendData(MPU_INT_ENABLE);
//	I2C_vidSendData(0x01);
//	I2C_vidSendStop();
//
//
//}
//
//void MPU_vdReadRawValues(MPU_Handeler_t *MPU_Handeler)
//{
//	I2C_vidSendStart();
//	I2C_vidSendSLA(MPU_SLA,I2C_WRITE);
//	I2C_vidSendData(MPU_ACCEL_XOUT_H);
//	I2C_vidSendSLA(MPU_SLA,I2C_READ);
//	MPU_Handeler->MPU_ACCEL_XOUT = ((u16)I2C_u8ReceiveWithNoAck()<<8) | ((u16)I2C_u8ReceiveWithNoAck());
//	MPU_Handeler->MPU_ACCEL_YOUT = ((u16)I2C_u8ReceiveWithNoAck()<<8) | ((u16)I2C_u8ReceiveWithNoAck());
//	MPU_Handeler->MPU_ACCEL_YOUT = ((u16)I2C_u8ReceiveWithNoAck()<<8) | ((u16)I2C_u8ReceiveWithNoAck());
//
//	MPU_Handeler->MPU_TEMP_OUT = ((u16)I2C_u8ReceiveWithNoAck()<<8) | ((u16)I2C_u8ReceiveWithNoAck());
//
//	MPU_Handeler->MPU_GYRO_XOUT = ((u16)I2C_u8ReceiveWithNoAck()<<8) | ((u16)I2C_u8ReceiveWithNoAck());
//	MPU_Handeler->MPU_GYRO_YOUT = ((u16)I2C_u8ReceiveWithNoAck()<<8) | ((u16)I2C_u8ReceiveWithNoAck());
//	MPU_Handeler->MPU_GYRO_ZOUT = ((u16)I2C_u8ReceiveWithNoAck()<<8) | ((u16)I2C_u8ReceiveWithNoAck());
//
//	I2C_vidSendStop();
//}
#include"avr/delay.h"
#include "../STD_TYPES.h"
#include "../BIT_math.h"
#include "MPU_6050_int.h"
#include "I2C_int.h"
void mpu6050_init(void)
{
_delay_ms(300);
I2C_vidSendStart();
I2C_vidSendSLA(0xd0);
I2C_vidSendData(MPU_SMPLRT_DIV);
I2C_vidSendData(0x07);	//sampling rate 1khz
I2C_vidSendStop();

I2C_vidSendStart();
I2C_vidSendSLA(0xd0);
I2C_vidSendData(MPU_PWR_MGMT_1);
I2C_vidSendData(0x01);   // x axises is reference or 0x00 internal clock
I2C_vidSendStop();
/*
I2C_Start();
I2C_Write(0xd0);
I2C_Write(INT_ENABLE);
I2C_Write(0x01);
I2C_Stop();
*/
I2C_vidSendStart();
I2C_vidSendSLA(0xd0);
I2C_vidSendData(MPU_GYRO_CONFIG);
I2C_vidSendData(0x18);
I2C_vidSendStop();

I2C_vidSendStart();
I2C_vidSendSLA(0xd0);
I2C_vidSendData(MPU_ACCEL_CONFIG);
I2C_vidSendData(0x18);
I2C_vidSendStop();

}

u16 x_axis (void ) // return accelerometer in x direction
{
	u8 x_high,x_low;
	u16 axsis_x;
	I2C_vidSendStart();
	I2C_vidSendSLA(0xd0);
	I2C_vidSendData(MPU_ACCEL_XOUT_H);
	I2C_vidSendStart();
	I2C_vidSendSLA(0xd1);
	x_high=I2C_u8ReceiveWithNoAck();
	I2C_vidSendStop();

	I2C_vidSendStart();
	I2C_vidSendData(0xd0);
	I2C_vidSendData(MPU_ACCEL_XOUT_L);
	I2C_vidSendStart();
	I2C_vidSendSLA(0xd1);
	x_low=I2C_u8ReceiveWithNoAck();
	I2C_vidSendStop();
	axsis_x = ((x_high<<8)|x_low)/16;
	return axsis_x;
}
u16 y_axis (void)		// return accelerometer in y direction
{



	u8 y_high,y_low;
	u16 axsis_y;
	I2C_vidSendStart();
	I2C_vidSendSLA(0xd0);
	I2C_vidSendData(MPU_ACCEL_YOUT_H);
	I2C_vidSendStart();
	I2C_vidSendSLA(0xd1);
	y_high=I2C_u8ReceiveWithNoAck();
	I2C_vidSendStop();

	I2C_vidSendStart();
	I2C_vidSendData(0xd0);
	I2C_vidSendData(MPU_ACCEL_XOUT_L);
	I2C_vidSendStart();
	I2C_vidSendSLA(0xd1);
	y_low=I2C_u8ReceiveWithNoAck();
	I2C_vidSendStop();
	axsis_y = ((y_high<<8)|y_low)/16;
	return axsis_y;


}

u16 temperature(void)		// return accelerometer in z direction
{







	u8 t_high,t_low;
	u16 axsis_t;
	I2C_vidSendStart();
	I2C_vidSendSLA(0xd0);
	I2C_vidSendData(MPU_TEMP_OUT_H);
	I2C_vidSendStart();
	I2C_vidSendSLA(0xd1);
	t_high=I2C_u8ReceiveWithNoAck();
	I2C_vidSendStop();

	I2C_vidSendStart();
	I2C_vidSendData(0xd0);
	I2C_vidSendData(MPU_TEMP_OUT_L);
	I2C_vidSendStart();
	I2C_vidSendSLA(0xd1);
	t_low=I2C_u8ReceiveWithNoAck();
	I2C_vidSendStop();
	axsis_t = ((t_high<<8)|t_low);
	return axsis_t;


}
s16 z_axis (void)		//return temprature
{

	u8 z_high,z_low;
	s16 axsis_y;
	I2C_vidSendStart();
	I2C_vidSendSLA(0xd0);
	I2C_vidSendData(MPU_ACCEL_ZOUT_H);
	I2C_vidSendStart();
	I2C_vidSendSLA(0xd1);
	z_high=I2C_u8ReceiveWithNoAck();
	I2C_vidSendStop();

	I2C_vidSendStart();
	I2C_vidSendData(0xd0);
	I2C_vidSendData(MPU_ACCEL_ZOUT_L);
	I2C_vidSendStart();
	I2C_vidSendSLA(0xd1);
	z_low=I2C_u8ReceiveWithNoAck();
	I2C_vidSendStop();
	axsis_y = ((z_high<<8)|z_low)/16;
	return axsis_y;




}
