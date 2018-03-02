#define SYSCTL_RCGCGPIO_R       (*((volatile unsigned long *)0x400FE608))
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))
#define SYSCTL_PRGPIO_R         (*((volatile unsigned long *)0x400FEA08))

#define GPIO_PORTE_CR_R         (*((volatile unsigned long *)0x40024524))
#define GPIO_PORTE_AMSEL_R      (*((volatile unsigned long *)0x40024528))
#define GPIO_PORTE_AFSEL_R      (*((volatile unsigned long *)0x40024420))
#define GPIO_PORTE_DIR_R        (*((volatile unsigned long *)0x40024400))
#define GPIO_PORTE_PCTL_R       (*((volatile unsigned long *)0x4002452C))
#define GPIO_PORTE_DEN_R        (*((volatile unsigned long *)0x4002451C))

void portEInit(void) {

	SYSCTL_RCGCGPIO_R |= 0x10;
	// SYSCTL_RCGC2_R |= 0x10;
	while( (SYSCTL_PRGPIO_R & 0x10) == 0);

	// GPIO_PORTE_LOCK_R = 0x4C4F434B; // port e doesn't need it.
	GPIO_PORTE_CR_R |= 0x3F; // allow changes to pins e5=>e0
	GPIO_PORTE_AMSEL_R &= ~0x3F; // disable analog
	GPIO_PORTE_AFSEL_R &= ~0x3F; // not alternative
	GPIO_PORTE_DIR_R |= 0x3F; // set pins as output
	GPIO_PORTE_PCTL_R = 0x00000000; // gpio clear bit pctl
	GPIO_PORTE_DEN_R |= 0x3F; // enable pins

}

#define GPIO_PORTD_CR_R         (*((volatile unsigned long *)0x40007524))
#define GPIO_PORTD_AMSEL_R      (*((volatile unsigned long *)0x40007528))
#define GPIO_PORTD_AFSEL_R      (*((volatile unsigned long *)0x40007420))
#define GPIO_PORTD_DIR_R        (*((volatile unsigned long *)0x40007400))
#define GPIO_PORTD_PCTL_R       (*((volatile unsigned long *)0x4000752C))
#define GPIO_PORTD_PDR_R        (*((volatile unsigned long *)0x40007514))
#define GPIO_PORTD_DEN_R        (*((volatile unsigned long *)0x4000751C))

void portDInit(void) {

	SYSCTL_RCGCGPIO_R |= 0x08;
	// SYSCTL_RCGC2_R |= 0x08;
	while( (SYSCTL_PRGPIO_R & 0x08) == 0);

	// GPIO_PORTE_LOCK_R = 0x4C4F434B; // port d doesn't need it.
	GPIO_PORTD_CR_R |= 0x03; // allow changes to pins d1=>d0
	GPIO_PORTD_AMSEL_R &= ~0x03; // disable analog
	GPIO_PORTD_AFSEL_R &= ~0x03; // not alternative
	GPIO_PORTD_DIR_R |= 0xFE; // set pin 0 as input and pin 1 as output
	GPIO_PORTD_PCTL_R = 0x00000000; // gpio clear bit pctl
	GPIO_PORTD_PDR_R |= 0x01;
	GPIO_PORTD_DEN_R |= 0x03; // enable pins

}