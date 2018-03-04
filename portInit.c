void portEInit(void) {

	SYSCTL_RCGCGPIO_R |= 0x10;
	// SYSCTL_RCGC2_R |= 0x10;
	while( (SYSCTL_PRGPIO_R & 0x10) == 0);

	// GPIO_PORTE_LOCK_R = 0x4C4F434B; // port e doesn't need it.
	// GPIO_PORTE_CR_R |= 0x3F; // allow changes to pins e5=>e0
	GPIO_PORTE_AMSEL_R &= ~0x3F; // disable analog
	GPIO_PORTE_AFSEL_R &= ~0x3F; // not alternative
	GPIO_PORTE_DIR_R |= 0x3F; // set pins as output
	GPIO_PORTE_PCTL_R = 0x00000000; // gpio clear bit pctl
	GPIO_PORTE_DEN_R |= 0x3F; // enable pins

}

void portDInit(void) {

	SYSCTL_RCGCGPIO_R |= 0x08;
	// SYSCTL_RCGC2_R |= 0x08;
	while( (SYSCTL_PRGPIO_R & 0x08) == 0);

	// GPIO_PORTD_LOCK_R = 0x4C4F434B; // port d doesn't need it.
	// GPIO_PORTD_CR_R |= 0x0C; // allow changes to pins d3=>d2
	GPIO_PORTD_AMSEL_R &= ~0x0C; // disable analog
	GPIO_PORTD_AFSEL_R &= ~0x0C; // not alternative
	GPIO_PORTD_DIR_R &= 0xFB; // set pin 2 as input
	GPIO_PORTD_DIR_R |= 0x08; // set pin 3 as output
	GPIO_PORTD_PCTL_R = 0x00000000; // gpio clear bit pctl
	GPIO_PORTD_PDR_R |= 0x04;
	GPIO_PORTD_DEN_R |= 0x0C; // enable pins

}
