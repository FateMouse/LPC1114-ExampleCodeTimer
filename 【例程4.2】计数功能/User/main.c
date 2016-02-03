/************************************************************************************** 
*   日期    ：2013年11月6日 (版权所有，翻版必究) 
*   目标    ：ARM Cortex-M0 LPC1114 
*   编译环境：KEIL 4.60
*   外部晶振：10Mhz(主频50M)
*   功能    ：学会使用通用定时器计数功能
*   作者    ：Ration
*   官方网址：http://www.rationmcu.com
*   淘宝店  ：http://ration.taobao.com
**************************************************************************************/
#include "lpc11xx.h"
#include "timer.h"
#include "uart.h"

int main()
{
	uint16_t temp1,temp2;
	
	UART_init(9600);
	T16B0_cnt_init();
	temp1 = LPC_TMR16B0->TC;
	
	while(1)
	{
		temp2 = LPC_TMR16B0->TC;
		if(temp2!=temp1)
		{
			temp1 = LPC_TMR16B0->TC;
 			UART_send_byte(temp1);
 		}
	}
}





