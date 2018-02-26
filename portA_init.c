/*
#include "stdint.h"
#include "C:/Keil/EE319Kware/inc/tm4c123gh6pm.h"

void SystemInit(){;}
	*/
void portA_init(void)
{
	SYSCTL_RCGCGPIO_R |= 0x01; //enable PORT A
	while((SYSCTL_PRGPIO_R&0x01)==0) {}
	GPIO_PORTA_LOCK_R= 0x4C4F434B; //giving write access to port A
	GPIO_PORTA_CR_R |= 0xFC; //commit register
	GPIO_PORTA_AFSEL_R &=0x03 ; // I/O
	GPIO_PORTA_PCTL_R &=0x03; //no alternative function
	GPIO_PORTA_AMSEL_R &=0x03; //Disable Analog function
	GPIO_PORTA_DIR_R |= 0xFC; //output pins
	GPIO_PORTA_DEN_R |= 0xFC; //Digital pins
	GPIO_PORTA_PUR_R &= 0x03; //pull up resitor register
}
/*
int main()
{
	SystemInit();
	portA_init();
	
	while(1)
	{
		GPIO_PORTA_DATA_R |= 0x04 ; //pin 2
		GPIO_PORTA_DATA_R &= 0x03 ;
		GPIO_PORTA_DATA_R |= 0x08 ; //pin 3
		GPIO_PORTA_DATA_R &= 0x03 ;
		GPIO_PORTA_DATA_R |= 0x0C ; //pin 2&3
		GPIO_PORTA_DATA_R &= 0x03 ;
		GPIO_PORTA_DATA_R |= 0x10 ; //pin 4
		GPIO_PORTA_DATA_R &= 0x03 ;
		GPIO_PORTA_DATA_R |= 0x20 ; //pin 5
		GPIO_PORTA_DATA_R &= 0x03 ;
		GPIO_PORTA_DATA_R |= 0x40 ; //pin 6
		GPIO_PORTA_DATA_R &= 0x03 ;
		GPIO_PORTA_DATA_R |= 0x80 ; //pin 7
		GPIO_PORTA_DATA_R &= 0x03 ;
		GPIO_PORTA_DATA_R |= 0xF0 ; // pin 4,5,6,7
		GPIO_PORTA_DATA_R &= 0x03 ;
		GPIO_PORTA_DATA_R |= 0xFC ; //pins 2 to 7
		GPIO_PORTA_DATA_R &= 0x03 ;
		
	}
  
}

*/