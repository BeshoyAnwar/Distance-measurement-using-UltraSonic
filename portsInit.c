void portAInit(void)
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
void portBInit(void){

	SYSCTL_RCGCGPIO_R |= 0x00000002; //SYSCTL_RCGCGPIO_R1 instead but it gives an ERROR!!
  while((SYSCTL_RCGCGPIO_R & 0x00000002) == 0 ) {};
	GPIO_PORTB_LOCK_R=0x4C4F434B;
	GPIO_PORTB_CR_R=0xFF;
	GPIO_PORTB_DIR_R |= 0xFF;   //all pins are output
	GPIO_PORTB_AFSEL_R =0;
	GPIO_PORTB_PCTL_R=0;
	GPIO_PORTB_AMSEL_R=0;
	GPIO_PORTB_DEN_R=0xFF;
	GPIO_PORTC_PUR_R=0;
}
