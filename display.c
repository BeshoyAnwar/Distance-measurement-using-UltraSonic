void showOnDisplays(uint16_t distance)
{
	unsigned char digit1 , digit2 , digit3 ;
	
	digit3 = distance /100;
	digit2 = distance /10 - digit3*10;
	digit1 = distance  - digit2*10 - digit3*100 ;
	digit1+='0'; digit2+='0'; digit3+='0';
	displayOnSeg1(digit1);//take an char digit1 to show it on Seg1
	displayOnSeg2(digit2);//take an char digit2 to show it on Seg2
	displayOnSeg3(digit3);//take an char digit3 to show it on Seg3
}	
void displayOnSeg1 (unsigned char digit1)
{	/* a => A2 , b => A3 , c => A4 , d => A5 , e => A6 , f => A7 , g => B0 */
switch(digit1)
	{
	case '1': // A3 , A4
					        GPIO_PORTA_DATA_R &= 0xE7; // 1110 01111
						GPIO_PORTB_DATA_R &= 0xFF; // 1111 1111
						break;
	case '2': // A2 , A3 , A5 , A6 , B0
					        GPIO_PORTA_DATA_R &= 0x93; // 1001 0011
						GPIO_PORTB_DATA_R &= 0xFE; // 1111 1110
						break;
	case '3': // A2 , A3 , A4 , A5 , B0
					        GPIO_PORTA_DATA_R &= 0xC3; // 1100 0011
						GPIO_PORTB_DATA_R &= 0xFE; // 1111 1110
						break;
	case '4': // A3 , A4 . A7 , B0
					        GPIO_PORTA_DATA_R &= 0x67; // 0110 0111 
						GPIO_PORTB_DATA_R &= 0xFE; // 1111 1110
						break;
	case '5': // A2 , A4 , A5 , A7 , B0
						GPIO_PORTA_DATA_R &= 0x47; // 0100 1011
						GPIO_PORTB_DATA_R &= 0xFE; // 1111 1110
						break;
	case '6': // A2 , A4 , A5 , A6 , A7 , B0
						GPIO_PORTA_DATA_R &= 0x0B; // 0000 1011
						GPIO_PORTB_DATA_R &= 0xFE; // 1111 1110
						break;
	case '7': // A2 , A3 , A4
						GPIO_PORTA_DATA_R &= 0xE3; // 1110 0011 
						GPIO_PORTB_DATA_R &= 0xFF; // 1111 1111
						break;
	case '8': // A2 , A3 , A4 , A5 , A6 , A7 , B0
						GPIO_PORTA_DATA_R &= 0x03; // 0000 0011 
						GPIO_PORTB_DATA_R &= 0xFE; // 1111 1110
						break;
	case '9': // A2 , A3 , A4 , A5 , A7 , B0
						GPIO_PORTA_DATA_R &= 0x43; // 0100 0011 
						GPIO_PORTB_DATA_R &= 0xFE; // 1111 1110
						break;
	default : // zero
						// A2 , A3 , A4 , A5 , A6 , A7 
						GPIO_PORTA_DATA_R &= 0x03; // 0000 0011 
						GPIO_PORTB_DATA_R &= 0xFF; // 1111 1111
						break;
	}
}
void displayOnSeg2(unsigned char digit2) {

    /*
                G F E D C B A
        port-b  7 6 5 4 3 2 1

            A
        F       B
            G
        E       C
            D
        
        http://www.physics.udel.edu/~watson/scen103/colloq2000/images/7seg1.gif

    */

    switch(digit2) {
        case '1': // B and C
            GPIO_PORTB_DATA_R &= 0xF3;
            break;
        case '2': // A, B, D, E and G
            GPIO_PORTB_DATA_R &= 0x49;
            break;
        case '3': // A, B, C, D and G
            GPIO_PORTB_DATA_R &= 0x61;
            break;
        case '4': // B, C, F and G
            GPIO_PORTB_DATA_R &= 0x33;
            break;
        case '5': // A, C, D, F and G
            GPIO_PORTB_DATA_R &= 0x25;
            break;
        case '6': // A, C, D, E, F and G
            GPIO_PORTB_DATA_R &= 0x05;
            break;
        case '7': // A, B, C
            GPIO_PORTB_DATA_R &= 0xF1;
            break;
        case '8': // A, B, C, D, E, F and G
            GPIO_PORTB_DATA_R &= 0x01;
            break;
        case '9': // A, B, C, D, F and G
            GPIO_PORTB_DATA_R &= 0x21;
            break;
        default: // case '0' // A, B, C, D, E and F
            GPIO_PORTB_DATA_R &= 0x81;
            break;
    }
}
void displayOnSeg3(unsigned char digit3)
{
	// a E0   -  b E1 - c	E2 - d	E3 - e	E4 - f	E5 - g	D0  
	// sagment is active low
	
	switch (digit3)
	{
		case '1' : // b , c low
			GPIO_PORTE_DATA_R &= 0x39 ; // portE mask 11111001
			GPIO_PORTD_DATA_R &= 0xFF ; // portD mask 11111111
			break;
		case '2' : // a , b , g , e , d low
			GPIO_PORTE_DATA_R &= 0xE4 ; // portE mask 1110 0100
			GPIO_PORTD_DATA_R &= 0xFE ; // portD mask 1111 1110
			break;
		case '3' : // a , b , c , d , g
			GPIO_PORTE_DATA_R &= 0xF0 ; // portE mask 1111 0000
			GPIO_PORTD_DATA_R &= 0xFE ; // portD mask 1111 1110
			break;
		case '4' : // b , c , f , g
			GPIO_PORTE_DATA_R &= 0xD9 ; // portE mask 1101 1001
			GPIO_PORTD_DATA_R &= 0xFE ; // portD mask 1111 1110
			break;
		case '5' : // a , c, d , f, g
			GPIO_PORTE_DATA_R &= 0xD2 ; // portE mask 1101 0010
			GPIO_PORTD_DATA_R &= 0xFE ; // portD mask 1111 1110
			break;
		case '6' : // a , c, d, e, f ,g
			GPIO_PORTE_DATA_R &= 0xC2 ; // portE mask 1100 0010
			GPIO_PORTD_DATA_R &= 0xFE ; // portD mask 1111 1110
			break;
		case '7' : // a, b, c
			GPIO_PORTE_DATA_R &= 0xF8 ; // portE mask 1111 1000
			GPIO_PORTD_DATA_R &= 0xFF ; // portD mask 1111 1111
			break;
		case '8' : // a, b, c, d, e, f, g 
			GPIO_PORTE_DATA_R &= 0xC0 ; // portE mask 1100 0000
			GPIO_PORTD_DATA_R &= 0xFE ; // portD mask 1111 1110
			break;
		case '9' : //a , b, c, d , f , g
			GPIO_PORTE_DATA_R &= 0xD0 ; // portE mask 1101 0000
			GPIO_PORTD_DATA_R &= 0xFE ; // portD mask 1111 1110
			break;
		default : //case'0' a, b, c, d, e, f
			GPIO_PORTE_DATA_R &= 0xC0 ; // portE mask 1100 0000
			GPIO_PORTD_DATA_R &= 0xFE ; // portD mask 1111 1111
			break;
		
		
	}
	
}
