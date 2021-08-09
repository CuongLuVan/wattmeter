/*
file:  sensor.c
description : manager all sensor of device
Create date : 19/2/2017
user cread : Lu Van Cuong
*/

#include "stm32f10x.h"
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_adc.h"
#include <stdio.h>
#include <string.h>

void setupAllADCSensor(void);
void getAllDataSensor(uint16_t *getvaluedata);


