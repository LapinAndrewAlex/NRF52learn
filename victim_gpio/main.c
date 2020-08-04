

#include "nrf_gpio.h"
#include "nrf_delay.h"
#define LED 17
#define BTN 13
//not energy efficient way//

int main(void){
    nrf_gpio_cfg_output(LED);
    nrf_gpio_cfg_output(18);
    nrf_gpio_cfg_output(19);
    nrf_gpio_cfg_output(20);
    nrf_gpio_cfg_input(BTN,NRF_GPIO_PIN_PULLUP);
    nrf_gpio_cfg_input(15,NRF_GPIO_PIN_PULLUP);


    nrf_gpio_pin_clear(17);
    nrf_gpio_pin_clear(18);
    nrf_gpio_pin_clear(19);
    nrf_gpio_pin_clear(20);
    nrf_delay_ms(200);

    nrf_gpio_pin_set(20);
    nrf_delay_ms(200);
    nrf_gpio_pin_set(19);
    nrf_delay_ms(200);
    nrf_gpio_pin_set(18);
    nrf_delay_ms(200);
    nrf_gpio_pin_set(17);


void bodyNULL ()
{


};


void bodyled1 ()
{
	nrf_gpio_pin_set(17);
	nrf_gpio_pin_set(18);
	nrf_gpio_pin_set(19);
	nrf_gpio_pin_set(20);
	nrf_delay_ms(200);
	nrf_gpio_pin_clear(17);
	nrf_gpio_pin_clear(18);
	nrf_gpio_pin_clear(19);
	nrf_gpio_pin_clear(20);
	nrf_delay_ms(200);

};
void bodyled2 ()
{
	for (uint32_t i = 17; i <= 20; i++)
	{
	   nrf_gpio_pin_clear(i);
	   nrf_delay_ms(200);
	   nrf_gpio_pin_set(i);
	}
};
void (*body)() = bodyNULL;
    while (true)
    {
    	body();
        if(!(nrf_gpio_pin_read(BTN)))
        {

        	body=bodyled2;

        }
        if(!(nrf_gpio_pin_read(15)))
        {
        	body=bodyled1;

        }

    }
}
