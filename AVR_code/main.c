/*
 * main.c
 *
 *  Created on: Apr 22, 2020
 *      Author: IoT Scientest
 */
#include"avr/delay.h"
#include"string.h"
#include"../STD_TYPES.h"
#include"../BIT_math.h"
#include"I2C_int.h"
#include"LCD_int.h"
#include"DIO_int.h"

#define BUZZER_BIN 4
int main (void )
{
	u16 y,x,t;
	s16 i,z;
	char arr [20];
	DIO_vdSetPortDirection(PORTB,OUTPUT);
	DIO_vdSetPinDirection(PORTC,PIN7,OUTPUT);
	DIO_vdSetPinDirection(PORTC,PIN6,OUTPUT);
	DIO_vdSetPinDirection(PORTC,PIN5,OUTPUT);
	DIO_vdSetPinDirection(PORTC,BUZZER_BIN,OUTPUT);
	DIO_vdSetPinDirection(PORTC,PIN3,OUTPUT);
	I2C_vidInit();
	mpu6050_init();
	LCD_vdInit();
	DIO_vdSetPinValue(PORTC,PIN3,LOW);
	LCD_vdWriteString("connecting");
	_delay_ms(1000);
	LCD_vdClearDisplay();
	LCD_vdWriteString("connected");
	_delay_ms(5000);
	while(1)
	{

		y=y_axis();
		x=x_axis();
		z=z_axis();
		t=temperature();
		LCD_vdClearDisplay();
		LCD_vdWriteString("Monitoring :)");
		if(z<90)
		{
			DIO_vdSetPinValue(PORTC,PIN3,HIGH);
			LCD_vdClearDisplay();
			LCD_vdWriteString(":( Falling");
			_delay_ms(100);

			LCD_vdClearDisplay();
			LCD_vdWriteString(":( Falling");
			_delay_ms(100);

			for(i=0;i<20;i++)
			{

				DIO_vdSetPinValue(PORTC,BUZZER_BIN,HIGH);
				_delay_ms(20);
				DIO_vdSetPinValue(PORTC,BUZZER_BIN,LOW);
				_delay_ms(20);
			}
		}
		DIO_vdSetPinValue(PORTC,PIN3,LOW);
		//		sprintf(arr,"x=%dy=%dt=%d",x,y,z);
		//		LCD_vdWriteString(arr);
		_delay_ms(1000);


	}
	return 0;
}
