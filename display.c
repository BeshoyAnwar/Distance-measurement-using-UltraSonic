void displayOnSeg3(char digit3)
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
		case '8' : // kolo =D
			GPIO_PORTE_DATA_R &= 0xC0 ; // portE mask 1100 0000
			GPIO_PORTD_DATA_R &= 0xFE ; // portD mask 1111 1110
			break;
		case '9' : //kolo without e
			GPIO_PORTE_DATA_R &= 0xD0 ; // portE mask 1101 0000
			GPIO_PORTD_DATA_R &= 0xFE ; // portD mask 1111 1110
			break;
		default :
			GPIO_PORTE_DATA_R |= 0x3F ; // portE mask 0011 1111
			GPIO_PORTD_DATA_R |= 0x01 ; // portD mask 0000 0001
			break;
		
		
	}
	
}

void showOnDisplays(uint16_t distance)
{
	char digit1 , digit2 , digit3 ;
	
	digit3 = distance /100;
	digit2 = distance /10 - digit3*10;
	digit1 = distance  - digit2*10 - digit3*100 ;
	digit1+='0'; digit2+='0'; digit3+='0';
	displayOnSeg1(digit1);//take an char digit3 to show it on Seg1
	displayOnSeg2(digit2);//take an char digit3 to show it on Seg2
	displayOnSeg3(digit3);//take an char digit3 to show it on Seg3
	
}
