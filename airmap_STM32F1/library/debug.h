#include "stm32f10x.h"
#include "stm32f10x_usart.h"
#include <stdio.h>
#include <string.h>
#define RX_BUF_SIZE	100
#define USER_DEBUG 1
#define USART_DEBUG USART3

/* Private macro */
void USART_Debug_Init(unsigned int BaudRate);
void USART_DMA_Init(unsigned int BaudRate);
void Clear_RXBuffer(void);
void SendUSART_DMA(const  char *pucBuffer);
void SendUSART(USART_TypeDef* USARTx,uint16_t ch);
int GetUSART(USART_TypeDef* USARTx);
void printDebug(char *data);
void showIntegerDebugDegit(int value);
void showFloatDebugDegit(float value);
void printDebugINT0(char *data);
void printDebugINT1(char *data,int value);
void printDebugINT2(char *data,int value,int value1);
void printDebugINT3(char *data,int value,int value1,int value2);
void printDebugFloat1(char *data,float value);
void printDebugFloat2(char *data,float value,float value1);
void printDebugFloat3(char *data,float value,float value1,float value2);
//void printDebug(char *data,int value);

#define printDebug(x)                   printDebugINT0(x)
#define printDebug1(x,x1)                printDebugINT1(x,x1)
#define printDebug2(x,x1,x2)             printDebugINT2(x,x1,x2)
#define printDebug3(x,x1,x2,x3)          printDebugINT3(x,x1,x2,x3)
#define printDebugF1(x,x1)                printDebugFloat1(x,x1)
#define printDebugF2(x,x1,x2)             printDebugFloat2(x,x1,x2)
#define printDebugF3(x,x1,x2,x3)          printDebugFloat3(x,x1,x2,x3)
