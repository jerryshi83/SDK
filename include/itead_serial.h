/********************************************************************
* File		:	itead_serial.h
* Desc		:	Provide the implementation of Arduino API on Serial
* Author	: 	Wu Pengfei
* Company	:	ITEAD Intelligent Systems Co.,Ltd.(http://imall.iteadstudio.com/)
* Date		:	2014/3/11
* History	:	Version		Modified by		Date		What
*				v1.0		Wu Pengfei		2014/3/11	Create
********************************************************************/

/*
 * (C) Copyright 2014
 * ITEAD Intelligent Systems Co., Ltd. <http://imall.iteadstudio.com>
 * Wu Pengfei<wupangfee@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 */

#ifndef __ITEAD_SERIAL_H__
#define __ITEAD_SERIAL_H__


#ifdef __cplusplus
extern "C"{
#endif

#include <stdint.h>

//typedef long unsigned int size_t;

/*
 * You CAN NOT use uart0, since is's is for interactive console by kernel.
 * Thus, ONLY, DEV_UARTn(n=2,3,4,7) are available for your purpose.
 */
#define		DEV_UART2		2
#define		DEV_UART3		3
#define		DEV_UART4		4
#define		DEV_UART7		7

/* 
 * We recommand these bauds blow.
 */
#define BAUD_9600  	9600
#define BAUD_19200 	19200
#define BAUD_38400 	38400
#define BAUD_57600 	57600
#define BAUD_115200 115200

uint32_t		Serialbegin(uint32_t dev, uint32_t baud);
uint32_t		Serialend(uint32_t dev);
uint32_t		Serialflush(uint32_t dev);
uint32_t		Serialwrite(uint32_t dev, uint8_t val);
uint32_t		Serialprint(uint32_t dev, const char *string);
uint32_t		Serialprintln(uint32_t dev, const char *string);
uint32_t		Serialavailable(uint32_t dev);
uint8_t			Serialread(uint32_t dev);

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
/*
 * Define class Serial_ 
 */
class Serial_  // : public Print
{
private:
	uint32_t dev;
	bool started;
	
public:
	Serial_(uint32_t dev);
	
	/* Override bool operator for if(Serial) */
	operator bool();
	
	int available(void);
	void begin(uint32_t baud_count);
	void end(void);
	void flush(void);
	size_t print(const char* string);
	size_t println(const char* string);
	int read(void);
	size_t write(uint8_t c);

};

extern Serial_ Serial2;
extern Serial_ Serial3;
extern Serial_ Serial4;
extern Serial_ Serial7;
extern Serial_ & Serial;

#endif

#endif
