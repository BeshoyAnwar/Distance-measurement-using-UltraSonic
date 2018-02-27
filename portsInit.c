void PLLInit(void){
	/* at the end of this fn the clk freq will be 80M */
	SYSCTL_RCC2_R|=0X80000000;//use RCC2
	SYSCTL_RCC2_R|=0X800;//bypass disabled
	
	SYSCTL_RCC_R=(SYSCTL_RCC_R&~0X7C0)+0X540;//select crystal value 16M
	SYSCTL_RCC2_R&=~0X70;//select osc source
	SYSCTL_RCC2_R&=~0X2000;//activate PLL
	SYSCTL_RCC2_R|=0X40000000;//set divider 
	SYSCTL_RCC2_R=(SYSCTL_RCC2_R&~0X1FC00000)+(4<<22);//div=4
	while(!SYSCTL_RCC2_R&0X40);//wait for PLL to lock
	SYSCTL_RCC2_R&=~0X800;//enable PLL by clearing bypass
}
void delay_ms(int delay){
	/* using clk freq 80M will make adelay with unit of mseconds */
	int x=0;//dummy variable
	SYSCTL_RCGCTIMER_R|=1;//connect the timer to clk
	x+=5;//make sure the clk is connected
	TIMER0_CTL_R&=~1;//disable the timer to configure it
	TIMER0_CFG_R=0;//32-Bit timer mode
	TIMER0_TAMR_R=2;//periodic mood
	TIMER0_TAMR_R|=0x10;//up select
	TIMER0_TAILR_R=80000*delay-1;//interval value to count
	TIMER0_ICR_R|=1;//clera the timeout flag
	TIMER0_CTL_R|=1;//timer enabled and counting starts
	while(!TIMER0_RIS_R&1);//wait to finish the interval
}
