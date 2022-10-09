#include <main.h>

void DC_start()
{
   output_high(PIN_B0);
   output_low(PIN_B1);
}

void DC_stop()
{
   output_low(PIN_B0);
   output_low(PIN_B1);
}
void main()
{
   int esik = 21;
   int16 temp = 0;
   setup_adc(ADC_CLOCK_DIV_2);
   setup_adc_ports(AN0);
   set_adc_channel(0);//AN5
   set_tris_a(0xFF);
   set_tris_b(0x00);
   set_tris_e(0x03);
   while(TRUE)
   {
      if (input(PIN_E0))
      {
         esik++;
         while (input(PIN_E0));
      }
      if (input(PIN_E1))
      {
         esik--;
         while (input(PIN_E1));
      }
      temp = read_adc() * 0.00763;
      if (temp >= esik)
      {
         DC_start();
         output_high(PIN_B7);
      }
      else if (temp < esik)
      {
         DC_stop();
         output_low(PIN_B7);
      }
   }

}
