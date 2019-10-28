#include<avr/io.h>
#define F_CPU 8000000
#include<util/delay.h>
#include<avr/interrupt.h>
#include<lcdavr.h>

 ISR(INT0_vect)//interruptfuncion/worktodo|while interupt is called|vect pointing toint0means- int0istheactivatedinteruupt
		 {  lcd_clear();
		    lcd_command(0x80);
			lcd_string("error");
			 _delay_ms(100);
			 lcd_clear();
			 }
void main()
{   DDRB=0xff;
   lcd_init();
   DDRD=(0<<PD2);//interrupt int0 is directed to work as input
   PORTD=(1<<PD2);//1 is assigned to pin2
   DDRA=0b00000011;
  sei();//enabling the interupt any one not mentioned
   GICR=(1<<INT0);//1 is asigned to int0(enabled input is int0) bcoz only into is used
   MCUCR=(0<<ISC00)|(1<<ISC01);//interrupt int0 is working on falling edge

   while(1)
   {
         PORTA=(1<<PA0);
		 _delay_ms(100);
		 PORTA=(1<<PA1);
		 _delay_ms(100);

		 }


	
		 }
