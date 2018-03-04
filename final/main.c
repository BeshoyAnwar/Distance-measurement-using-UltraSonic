#include "G:\engineering_programs\keilv4\EE319Kware\inc\tm4c123gh6pm.h"
#include "stdint.h"
#include "portsInit.h"
#include "measureDistance.h"
#include "display.h"
#define red 0x02
#define blue 0x04
#define green 0x08
/*void SystemInit(void){}*/
int main(void)
{	volatile int time;int i=0;
		PLLInit();
		portAInit();
		portBInit();
		portDInit();
		portEInit();
		portFInit();
		while(1){
				uint16_t distance;
				if((GPIO_PORTF_DATA_R&0x11)==0x10||(GPIO_PORTF_DATA_R&0x11)==0x01){
					//sw1 or sw is pushed 
					GPIO_PORTF_DATA_R=red;//start initiating indicator
					ultrasonicInit();
					GPIO_PORTF_DATA_R=blue;// end initiating indicator
					distance=measureDistance_cm();
					showOnDisplays(distance);
					GPIO_PORTF_DATA_R=green;// distace on segments is valid nw
				}
		}
		return 0;
}