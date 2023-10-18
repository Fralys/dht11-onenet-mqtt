
#include "led.h"
#include "key.h"
#include "beep.h"
#include "delay.h"
#include "sys.h"
#include "timer.h"
#include "usart.h"
#include "dht11.h"
#include "bh1750.h"
//#include "oled.h"
//#include "OLED.h"
#include "exti.h"
#include "stdio.h"
#include "esp8266.h"
#include "onenet.h"

u8 tem=0;
void Hardware_Init(void)
{
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	//�жϿ�������������

	delay_init();									//systick��ʼ��
	
	Usart1_Init(115200);							//����1����ӡ��Ϣ��
	
	Usart2_Init(115200);							//����2������ESP8266��
//	
//	IIC_Init();										//���IIC��ʼ��
//	
	BEEP_Init();									//��������ʼ��

	//OLED_Init();
	
	UsartPrintf(USART_DEBUG, " Hardware init OK\r\n");
}

/*
************************************************************
*	�������ƣ�	main
*
*	�������ܣ�	
*
*	��ڲ�����	��
*
*	���ز�����	0
*
*	˵����		
************************************************************
*/
int main(void)
{
	
	unsigned short timeCount = 0;	//���ͼ������
	
	unsigned char *dataPtr = NULL;
	
					//��ʼ����ΧӲ��
	Hardware_Init();
	ESP8266_Init();					//��ʼ��ESP8266
	
	OneNet_DevLink();
	//{UsartPrintf(USART_DEBUG, "OneNet_online\r\n");

//����OneNE
	//OLED_ShowString(1,1,"OneNet_online");
//	OLED_Refresh_Line("NVIC");
	//DelayXms(500);
	
	//GPIO_SetBits(GPIOB,GPIO_Pin_8);	//������ʾ����ɹ�
	//DelayXms(500);
//	UsartPrintf(USART_DEBUG, "ATMCUok\r\n");

	
	
//	while(1)
//	{
//		
//		if(++timeCount >= 500)									//���ͼ��5s
//		{
//			SHT20_GetValue();
//			
//			UsartPrintf(USART_DEBUG, "OneNet_SendData\r\n");
//			OneNet_SendData();									//��������
//			
//			timeCount = 0;
//			ESP8266_Clear();
//		}
//		
//		dataPtr = ESP8266_GetIPD(0);
//		if(dataPtr != NULL)
//			OneNet_RevPro(dataPtr);
//		
//		DelayXms(10);
//	
//	}

}

//u8 alarmFlag = 0;//�Ƿ񱨾��ı�־
//u8 alarm_is_free = 10;//�������Ƿ��ֶ�������������ֶ�����������Ϊ0



//u8 humidityH;	  //ʪ����������
//u8 humidityL;	  //ʪ��С������
//u8 temperatureH;   //�¶���������
//u8 temperatureL;   //�¶�С������
//extern char oledBuf[20];
//float Light = 0; //���ն�
//u8 Led_Status = 0;

//char PUB_BUF[256];//�ϴ����ݵ�buf
//const char *devSubTopic[] = {"/mysmarthome/sub"};
//const char devPubTopic[] = "/mysmarthome/pub";
//u8 ESP8266_INIT_OK = 0;//esp8266��ʼ����ɱ�־



// int main(void)
// {

//	unsigned short timeCount = 0;	//���ͼ������
//	unsigned char *dataPtr = NULL;
//	static u8 lineNow;
//	 
//	 delay_init();	    	 //��ʱ������ʼ��	  
//	LED_Init();		  	//��ʼ����LED���ӵ�Ӳ���ӿ�
//	 
////	 while(1)
////	 { 
////	  GPIO_ResetBits(GPIOA,GPIO_Pin_8); //LED0�����
////		GPIO_SetBits(GPIOD,GPIO_Pin_2);//LED1�����
////		delay_ms(300);
////		GPIO_SetBits(GPIOA,GPIO_Pin_8);//LED0�����
////		GPIO_ResetBits(GPIOD,GPIO_Pin_2);//LED1�����
////		delay_ms(300);
////	 }
////	 
//	Usart1_Init(115200);//debug����
//		DEBUG_LOG("\r\n");
//		DEBUG_LOG("UART1��ʼ��			[OK]");
//	delay_init();	    	 //��ʱ������ʼ��	
//		DEBUG_LOG("��ʱ������ʼ��			[OK]");
//	OLED_Init();
//	OLED_ColorTurn(0);//0������ʾ��1 ��ɫ��ʾ
//  OLED_DisplayTurn(0);//0������ʾ 1 ��Ļ��ת��ʾ
//	OLED_Clear();
//	 	DEBUG_LOG("OLED1��ʼ��			[OK]");
//		OLED_Refresh_Line("OLED");

//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// �����ж����ȼ�����2
//		DEBUG_LOG("�ж����ȳ�ʼ��			[OK]");
//		OLED_Refresh_Line("NVIC");
//	LED_Init();		  	//��ʼ����LED���ӵ�Ӳ���ӿ�
//		DEBUG_LOG("LED��ʼ��			[OK]");
//		OLED_Refresh_Line("Led");
//	KEY_Init();          	//��ʼ���밴�����ӵ�Ӳ���ӿ�
//		DEBUG_LOG("������ʼ��			[OK]");
//		OLED_Refresh_Line("Key");
//	EXTIX_Init();		//�ⲿ�жϳ�ʼ��
//		DEBUG_LOG("�ⲿ�жϳ�ʼ��			[OK]");
//		OLED_Refresh_Line("EXIT");
//	BEEP_Init();
//		DEBUG_LOG("��������ʼ��			[OK]");
//		OLED_Refresh_Line("Beep");
//	DHT11_Init();
//		DEBUG_LOG("DHT11��ʼ��			[OK]");
//		OLED_Refresh_Line("DHT11");
//  BH1750_Init();
//		DEBUG_LOG("BH1750��ʼ��			[OK]");
//		OLED_Refresh_Line("BH1750");
//	Usart2_Init(115200);//stm32-8266ͨѶ����
//		DEBUG_LOG("UART2��ʼ��			[OK]");
//		OLED_Refresh_Line("Uart2");
//	
//		DEBUG_LOG("Ӳ����ʼ��			[OK]");
//		
//	DEBUG_LOG("��ʼ��ESP8266 WIFIģ��...");
//	if(!ESP8266_INIT_OK){
//		OLED_Clear();
//		sprintf(oledBuf,"Waiting For");
//		OLED_ShowString(16,0,(u8*)oledBuf,16);//8*16 ��ABC��
//		sprintf(oledBuf,"WiFi");
//		OLED_ShowString(48,18,(u8*)oledBuf,16);//8*16 ��ABC��
//		sprintf(oledBuf,"Connection");
//		OLED_ShowString(24,36,(u8*)oledBuf,16);//8*16 ��ABC��
//		OLED_Refresh();
//	}
//	ESP8266_Init();					//��ʼ��ESP8266
//	OLED_Clear();
//	sprintf(oledBuf,"Waiting For");
//	OLED_ShowString(16,0,(u8*)oledBuf,16);//8*16 ��ABC��
//	sprintf(oledBuf,"MQTT Server");
//	OLED_ShowString(16,18,(u8*)oledBuf,16);//8*16 ��ABC��
//	sprintf(oledBuf,"Connection");
//	OLED_ShowString(24,36,(u8*)oledBuf,16);//8*16 ��ABC��
//	OLED_Refresh();	
//	while(OneNet_DevLink()){//����OneNET
//		delay_ms(500);
//	}		
//	
//	OLED_Clear();	
//	
//	TIM2_Int_Init(4999,7199);
//	TIM3_Int_Init(2499,7199);
//	
//	BEEP = 1;//������ʾ����ɹ�
//	delay_ms(250);
//	BEEP = 0;
//	
//	OneNet_Subscribe(devSubTopic, 1);
//	
//	while(1)
//	{
//		if(timeCount % 40 == 0)//1000ms / 25 = 40 һ��ִ��һ��
//		{
//			/********** ��ʪ�ȴ�������ȡ����**************/
//			DHT11_Read_Data(&humidityH,&humidityL,&temperatureH,&temperatureL);
//			
//			/********** ���նȴ�������ȡ����**************/
//			if (!i2c_CheckDevice(BH1750_Addr))
//			{
//				Light = LIght_Intensity();
//			}
//			
//			/********** ��ȡLED0��״̬ **************/
//			Led_Status = GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_8);
//			
//			/********** �����߼� **************/
//			if(alarm_is_free == 10)//����������Ȩ�Ƿ���� alarm_is_free == 10 ��ʼֵΪ10
//			{
//				if((humidityH < 80) && (temperatureH < 30) && (Light < 1000))alarmFlag = 0;
//				else alarmFlag = 1;
//			}
//			if(alarm_is_free < 10)alarm_is_free++;
////			DEBUG_LOG("alarm_is_free = %d", alarm_is_free);
////			DEBUG_LOG("alarmFlag = %d\r\n", alarmFlag);

//			
//			/********** ���������Ϣ **************/
//			DEBUG_LOG(" | ʪ�ȣ�%d.%d C | �¶ȣ�%d.%d %% | ���նȣ�%.1f lx | ָʾ�ƣ�%s | ��������%s | ",
//			humidityH,humidityL,temperatureH,temperatureL,Light,Led_Status?"�ر�":"��������",alarmFlag?"��������":"ֹͣ");
//		}
//		if(++timeCount >= 200)	// 5000ms / 25 = 200 ���ͼ��5000ms
//		{
//			Led_Status = GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4);//��ȡLED0��״̬
//			DEBUG_LOG("==================================================================================");
//			DEBUG_LOG("�������� ----- OneNet_Publish");
//			sprintf(PUB_BUF,"{\"Hum\":%d.%d,\"Temp\":%d.%d,\"Light\":%.1f,\"Led\":%d,\"Beep\":%d}",
//				humidityH,humidityL,temperatureH,temperatureL,Light,Led_Status?0:1,alarmFlag);
//			OneNet_Publish(devPubTopic, PUB_BUF);
//			DEBUG_LOG("==================================================================================");
//			timeCount = 0;
//			ESP8266_Clear();
//		}
//		
//		dataPtr = ESP8266_GetIPD(3);
//		if(dataPtr != NULL)
//			OneNet_RevPro(dataPtr);
//		delay_ms(10);
//	}
//}
/*
 * microlib_printf.c
 *
 *  Created on: Dec 26, 2015
 *      Author: Yang
 *   
 *    keil�����ڹ�ѡʹ��microlibʱ����ӳ��printf������������ļ�
 *    ����ڹ����ڼ�����Ч(ע�⣺����ʹ��microlib��Ч)
 */

//include "stm32f10x.h"  
 
//��ӳ��fputc�������˺���Ϊ�����������Ļ�������
//int fputc(int ch, FILE *f)
//{
////	while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);    //�޸Ĵ˴���whileѭ������
////	USART_SendData(USART1, (uint8_t) ch);                           //��Ĵ��������޸�����˿�
//	return ch;
//}
////���뺯��������
//int GetKey (void)  
//{ 
////	while (!(USART1->SR & USART_FLAG_RXNE));                  //����
////	return ((int)(USART1->DR & 0x1FF));
//}

