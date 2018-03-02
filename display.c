#define GPIO_PORTB_DATA_R       (*((volatile unsigned long *)0x400053FC))

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