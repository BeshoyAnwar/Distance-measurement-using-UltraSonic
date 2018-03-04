#include "G:\engineering_programs\keilv4\EE319Kware\inc\tm4c123gh6pm.h"
#include "stdint.h"
void delay_us(int delay){
	/* using clk freq 80M will make adelay with unit of useconds */
	int x=0;//dummy variable
	SYSCTL_RCGCTIMER_R|=1;//connect the timer to clk
	x+=5;//make sure the clk is connected
	TIMER0_CTL_R&=~1;//disable the timer to configure it
	TIMER0_CFG_R=0;//32-Bit timer mode
	TIMER0_TAMR_R=2;//periodic mode
	TIMER0_TAMR_R|=0x10;//up select
	TIMER0_TAILR_R=80*delay-1;//interval value to count
	TIMER0_ICR_R|=1;//clear the timeout flag
	TIMER0_CTL_R|=1;//timer enabled and counting starts
	while(!TIMER0_RIS_R&1);//wait to finish the interval
}
void ultrasonicInit(void){
	//***start initiating the ultrasonic***//
			
			//D2 is Reci and D3 is Trig
			GPIO_PORTD_DATA_R&=~0x8;//reset the trig 
			delay_us(2);// wait for trig to turn to low
			
			GPIO_PORTD_DATA_R|=0x8;// set it high 
			delay_us(10);// remain it high for 10us
			
			GPIO_PORTD_DATA_R&=~0x8;// and back to low again
			
	//***end initiating the ultrasonic***//
}
uint64_t pulseInHigh(void)
{
	//initiate timer0 as periodic with up counting to 0xffff.ffff
	uint64_t CurrentTime_us;
	int x=0;//dummy variable
	while((GPIO_PORTD_DATA_R & 0x4)==0); //D2 is Low

	SYSCTL_RCGCTIMER_R|=1;//connect the timer to clk
	x+=5;//make sure the clk is connected
	TIMER0_CTL_R&=~1;//disable the timer to configure it
	TIMER0_CFG_R=0;//32-Bit timer mode
	TIMER0_TAMR_R=2;//periodic mood
	TIMER0_TAMR_R|=0x10;//up select
	TIMER0_TAILR_R=0xFFFFFFFF;//interval value to count
	TIMER0_ICR_R|=1;//clear the timeout flag
	TIMER0_CTL_R|=1;//timer enabled and counting starts
	
	while((GPIO_PORTD_DATA_R & 0x4)==0x04);  //D2 is High

	CurrentTime_us=TIMER0_TAV_R/80; //get the current value of the timer
	TIMER0_CTL_R&=~1; // disable the timer
	return CurrentTime_us;
}
uint16_t measureDistance_cm(void)
{
	uint64_t duration=pulseInHigh();// measure the time it took the sound to bounce back
	return duration / 29 / 2;
	/*** calculate the distance (in centimetres)     ****
	**** 1/29 velocity of audiowaves in air(cm/us)&  ****
	**** 2 is due to going and return of this waves  ***/

}