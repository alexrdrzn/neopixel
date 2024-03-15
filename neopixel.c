/*
 * neopixel.c
 *
 *  Created on: Mar 15, 2024
 *      Author: InnovationHKI
 */

#include <string.h>
#include "main.h"
#include "spi.h"
#include "neopixel.h"


#define NEOPIXEL_FILL_BUFFER(COLOR) \
    for( uint8_t mask = 0xC0; mask; mask >>= 1 ) { \
        if( COLOR & mask ) { \
            *ptr++ = 0xfc; \
        } else { \
            *ptr++ = 0x80; \
        } \
    }

uint8_t neopixel_buffer[NEOPIXEL_BUFFER_SIZE];

void neopixel_init()
{
	memset(neopixel_buffer, 0, NEOPIXEL_BUFFER_SIZE);
	neopixel_send_spi();
}

void neopixel_send_spi()
{
	HAL_SPI_Transmit(&NEOPIXEL_SPI_HANDLE, neopixel_buffer, NEOPIXEL_BUFFER_SIZE, HAL_MAX_DELAY);
}

void neopixel_single(uint16_t led, uint8_t r, uint8_t g, uint8_t b)
{
	uint8_t *ptr = &neopixel_buffer[24 * led];
	NEOPIXEL_FILL_BUFFER(g);
	NEOPIXEL_FILL_BUFFER(r);
	NEOPIXEL_FILL_BUFFER(b);
}

void neopixel_all(uint8_t r, uint8_t g, uint8_t b)
{
	uint8_t *ptr = neopixel_buffer;
	for(uint16_t i; i < NEOPIXEL_NUM_LED; i++)
	{
		NEOPIXEL_FILL_BUFFER(g);
		NEOPIXEL_FILL_BUFFER(r);
		NEOPIXEL_FILL_BUFFER(b);
	}
}
