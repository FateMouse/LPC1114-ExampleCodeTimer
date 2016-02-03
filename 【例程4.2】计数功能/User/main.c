/************************************************************************************** 
*   ����    ��2013��11��6�� (��Ȩ���У�����ؾ�) 
*   Ŀ��    ��ARM Cortex-M0 LPC1114 
*   ���뻷����KEIL 4.60
*   �ⲿ����10Mhz(��Ƶ50M)
*   ����    ��ѧ��ʹ��ͨ�ö�ʱ����������
*   ����    ��Ration
*   �ٷ���ַ��http://www.rationmcu.com
*   �Ա���  ��http://ration.taobao.com
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





