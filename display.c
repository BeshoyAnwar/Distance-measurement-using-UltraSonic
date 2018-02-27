void displayOnSeg1 (char digit1)
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
