/**
 * Copyright (c) 2014 - 2018, Nordic Semiconductor ASA
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form, except as embedded into a Nordic
 *    Semiconductor ASA integrated circuit in a product or a software update for
 *    such product, must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 *
 * 3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * 4. This software, with or without modification, must only be used with a
 *    Nordic Semiconductor ASA integrated circuit.
 *
 * 5. Any software provided in binary form under this license must not be reverse
 *    engineered, decompiled, modified and/or disassembled.
 *
 * THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
/** @file
 * @defgroup nrf_dev_wdt_example_main main.c
 * @{
 * @ingroup nrf_dev_wdt_example
 * @brief WDT Example Application main file.
 *
 * This file contains the source code for a sample application using WDT.
 *
 */

#include <stdbool.h>
#include <stdint.h>

#include "nrf.h" //board specification


#include "bsp.h" //button lib

#include "app_timer.h"

#include "app_error.h"

#include "nrf_drv_wdt.h"
#include "nrf_drv_clock.h"

#include "nrf_delay.h"
#include "app_util_platform.h"


int main(void)
{


    app_timer_init();
    bsp_board_init(BSP_INIT_LEDS);//Configure all LEDs on board.
    bsp_board_init(BSP_INIT_BUTTONS);
    bsp_board_leds_init();

    while (1)
    {
    	 //Indicate program start on LEDs.
    	    for (uint32_t i = 0; i < 4; i++)
    	    {
    	        bsp_board_led_on(i);
    	    }

    	    nrf_delay_ms(400);

    	    for (uint32_t i = 0; i < 4; i++)
    	    {
    	       	bsp_board_led_off(i);

    	    }
    	    nrf_delay_ms(400);
    }
}

