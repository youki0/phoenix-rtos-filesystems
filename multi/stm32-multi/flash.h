/*
 * Phoenix-RTOS
 *
 * STM32L1 flash driver.
 *
 * Copyright 2017, 2018 Phoenix Systems
 * Author: Jakub Sejdak, Aleksander Kaminski
 *
 * This file is part of Phoenix-RTOS.
 *
 * %LICENSE%
 */

#ifndef _FLASH_H_
#define _FLASH_H_

#include ARCH
#include "rtc.h"
#include "common.h"

#define FLASH_PAGE_SIZE         256
#define FLASH_PROGRAM_1_ADDR    0x08000000
#define FLASH_PROGRAM_2_ADDR    0x08030000
#define FLASH_PROGRAM_SIZE      (192 * 1024)
#define FLASH_EEPROM_1_ADDR     0x08080000
#define FLASH_EEPROM_2_ADDR     0x08081800
#define FLASH_EEPROM_SIZE       (6 * 1024)
#define FLASH_OB_1_ADDR         0x1ff80000
#define FLASH_OB_2_ADDR         0x1ff80080
#define FLASH_OB_SIZE           32


static inline int flash_activeBank(void)
{
	u32 pc = getPC();

	if (pc < FLASH_PROGRAM_1_ADDR)
		pc += FLASH_PROGRAM_1_ADDR;

	return !(pc < FLASH_PROGRAM_2_ADDR);
}


extern size_t flash_readData(u32 offset, char *buff, size_t size);


extern size_t flash_writeData(u32 offset, const char *buff, size_t size);


extern int flash_init(void);


#endif