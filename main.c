#include "C:\Users\Eþref\Desktop\PIC\Projeler\LM35 Dijital Sýcaklýk\main.h"
unsigned long int data; // unsigned 16 bit int
float voltage,temperature;

void main()
{
   setup_adc_ports(AN0);
   setup_adc(adc_clock_div_32);
   setup_psp(PSP_DISABLED);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);
   setup_vref(FALSE);
   set_adc_channel(0);
   delay_us(20);
   set_tris_b(0x00);
   set_tris_a(0x01);
   output_b(0x00);
 while(1)
 {
	 data=read_adc();
	 
	 voltage=(0.0048828125*data)*1000; // converting mV voltage
	 temperature=(voltage/10)+2; 
	 if (temperature > 9)
	 {
		output_high(pin_b7); // if temperature is higher than 9, opening led on b7 pin for test purpose
	 }
	 else
	 {
		output_low(pin_b7);
	 }
 }
}
