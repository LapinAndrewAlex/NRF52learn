#include "nrf_gpio.h"        //GPIO Haardware Driver
#include "nrf_drv_gpiote.h"  // GPIOTE Driver
#include "nrf_drv_ppi.h"	 //PPI Driver

#define LED 17
#define BTN 13



/*
###GPIOTE and PPI

Instead of using an interrupt handler you can toggle the LED directly using the PPI peripheral.
You will need to add an additional GPIOTE channel for the LED task. And then connect the button
event with the LED task using PPI. This does not use any interrupt handlers and therefore
never start the CPU. Hence lower power consumption.
*/



int main(void){
    //Initialize GPIOTE driver
    nrf_drv_gpiote_init();

    //Configure button with pullup and event on both high and low transition
    nrf_drv_gpiote_in_config_t btn_config = GPIOTE_CONFIG_IN_SENSE_TOGGLE(false);
    btn_config.pull = NRF_GPIO_PIN_PULLUP;
    nrf_drv_gpiote_in_init(BTN, &btn_config, NULL); //Assign button config to a GPIOTE channel
    uint32_t btn_addr = nrf_drv_gpiote_in_event_addr_get(BTN); //Store event address from GPIOTE event
    nrf_drv_gpiote_in_event_enable(BTN, false); //Enable event

    //Configure LED toggle task
    nrf_drv_gpiote_out_config_t led_config = GPIOTE_CONFIG_OUT_TASK_TOGGLE(false);
    nrf_drv_gpiote_out_init(LED, &led_config); //Assign LED config to a GPIOTE channel
    uint32_t led_addr = nrf_drv_gpiote_out_task_addr_get(LED); //Store task address from GPIOTE task
    nrf_drv_gpiote_out_task_enable(LED); //Enable task

    //Connect GPIOTE event and task using PPI peripheral
    nrf_drv_ppi_init();
    nrf_ppi_channel_t ppi_channel = NRF_PPI_CHANNEL0;
    nrf_drv_ppi_channel_alloc(&ppi_channel);
    nrf_drv_ppi_channel_assign(ppi_channel, btn_addr, led_addr); // Connect the previously stored task and event addresses
    nrf_drv_ppi_channel_enable(ppi_channel);

    for(;;)__WFE(); //CPU sleep while waiting for event
}
