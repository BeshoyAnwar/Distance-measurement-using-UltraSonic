	/*GPIO_PORTA_DATA_R=5;
			GPIO_PORTB_DATA_R=5;
			GPIO_PORTD_DATA_R=2;
			GPIO_PORTE_DATA_R=3;
			GPIO_PORTF_DATA_R=0;*/
	
	/*	while(!(GPIO_PORTF_DATA_R&0x1));
		Timer1Init();
		while(!TIMER1_RIS_R&1){
			if(!(GPIO_PORTF_DATA_R&0x1)){
				time=TIMER1_TAR_R;
				TIMER1_CTL_R&=~1;
				GPIO_PORTF_DATA_R=0x02;
				delay_ms(100);
				break;}
		}	*/
	
	/*	delay_ms(100);*/
		//delay_us(10000000);
		/*for(i=0;i<1000000;i++);*/
			/*
			GPIO_PORTF_DATA_R=0x0;
		delay_ms(100);*/
		//delay_us(10000000);
		/*for(i=0;i<1000000;i++);*/
		//delay_us(1000);
	
	/*
		if((GPIO_PORTF_DATA_R&0x11)==0x10){
			
			GPIO_PORTF_DATA_R=0x02;//red
		}
		else if((GPIO_PORTF_DATA_R&0x11)==0x01){
			
			GPIO_PORTF_DATA_R=0x04;//blue
		}
		else if((GPIO_PORTF_DATA_R&0x11)==0x00){
			
			GPIO_PORTF_DATA_R=0x08;//green
		}
		else{
			
			GPIO_PORTF_DATA_R=0;
		}
	*/