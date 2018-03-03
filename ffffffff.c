int Timer1Init(void)//initiate timer1 as periodic with up counting to 0xffff.ffff
{
int CurrentTime;
int x=0;//dummy variable
while((GPIO_PORTD_DATA_R & 0x01)==0); //D0 is Low

	SYSCTL_RCGCTIMER_R|=1;//connect the timer to clk
	x+=5;//make sure the clk is connected
	TIMER0_CTL_R&=~1;//disable the timer to configure it
	TIMER0_CFG_R=0;//32-Bit timer mode
	TIMER0_TAMR_R=2;//periodic mood
	TIMER0_TAMR_R|=0x10;//up select
	TIMER0_TAILR_R=0xFFFFFFFF;//interval value to count
	TIMER0_ICR_R|=1;//clear the timeout flag
	TIMER0_CTL_R|=1;//timer enabled and counting starts
	
	while((GPIO_PORTD_DATA_R & 0x01)==0x01);  //D0 is High

	CurrentTime=TIMER0_TAV_R; //get the current value of the timer
	TIMER0_CTL_R&=~1; // disable the timer
	return CurrentTime;

}
