#include "Config.h"


void Port_Init()
{
	DDRC = 0xFF;
	DDRD |= 0x03;
}
void ADC_Init()
{
	ADMUX  = 0x00;
	ADCSRA = 0x83;
}

uint16 Read_ADC()
{
	ADCSRA |= (1<<ADSC);

	while(  ! ( ADCSRA & (1<<ADIF) ) );

	ADCSRA |= (1<<ADIF);

	return ADC;
}

int main ()
{
	Port_Init();
	ADC_Init();

	while(1)
	{
		uint16 x = Read_ADC();
		PORTC = x;
		PORTD = (x>>8);
	}

	return 0;
}
