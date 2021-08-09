/*
file:  main.c
Create date : 19/2/2017
user cread : Lu Van Cuong
*/
#include "stm32f10x.h"
#include "debug.h"
#include "sensor.h"
#include "define.h"
#define USERTIME10S_VOLTIVE
int main(void)
{
  uint8_t i;
  uint16_t data[7];
	uint16_t dataout[6];
	float voltivesensor;
	uint32_t time_old,time_new;



  //E_ReturnRequest return_data;
	USART_Debug_Init(115200);
  printDebug("START:~~~~~~~main");
	setupAllADCSensor();
  if (SysTick_Config(SystemCoreClock / 1000))
  { 
		printDebug("START:Error system tick");
    /* Capture error */ 
    while (1);
  }
	time_old=getSysticTime();
  while (1)
  {
		time_new=getSysticTime();
		#ifdef WATTMETTER
			if(time_old!=time_new){
				time_old=time_new;
				getAllDataSensor(&data[0]);
				for(i=0;i<6;i++) dataout[i]=(uint16_t)(data[i]/data[6]*3300);
				printDebug2("u1=%dV i1=%dA",dataout[0],dataout[3]);
				printDebug2("u2=%dV i2=%dA",dataout[1],dataout[4]);
				printDebug2("u3=%dV i3=%dA",dataout[2],dataout[5]);	
			}
		#endif
		#ifdef USERTIME10S_VOLTIVE
		  if((time_new%10000)==0){
				getAllDataSensor(&data[0]);
				voltivesensor=data[0]/1241*1.5;
				printDebugF1("The curent %fV",voltivesensor);
			}
		#endif
  }
  printDebug("End:main");
}

void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}

