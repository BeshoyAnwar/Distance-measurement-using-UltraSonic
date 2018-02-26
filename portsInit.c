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
