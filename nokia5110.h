/* Nokia 5110 LCD AVR and SAM3x8e Library
 *
 * Copyright (C) 2018 Dexter Johnson.
 * Modified by Dexter Johnson (Dextersamplifierrepair(+at+)gmail.com)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public Licence
 * as published by the Free Software Foundation; either version 3
 * of the Licence, or (at your option) any later version.
 *
 * Original library written by Sergey Denisov aka LittleBuster (DenisovS21@gmail.com)
 */

#ifndef INC_NOKIA_5110_H
#define INC_NOKIA_5110_H
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __AVR__

#include <avr/pgmspace.h>

#endif

#include <stdint.h>

#ifdef __AVR__
/*
 * LCD's port
 */


#define PORT_LCD PORTB // Where you write Data
#define DDR_LCD DDRB // Where you set I/O

/*
 * LCD's pins
 */
#define LCD_SCE PB1 // Pin 9 on the Arduino Uno Board
#define LCD_RST PB2 // Pin 10 on the Arduino Uno Board
#define LCD_DC PB3 // Pin 11 on the Arduino Uno Board
#define LCD_DIN PB4 // Pin 12 on the Arduino Uno Board
#define LCD_CLK PB5 // Pin 13 on the Arduino Uno Board

#endif

#ifdef  __SAM3X8E__

#include "sam3x8e.h"

#define PORT_LCD REG_PIOA_SODR // Where you write Data
#define DDR_LCD  REG_PIOC_OER // Where you set I/O Direction
/*
 * LCD's pins
 */
#define LCD_SCE PIO_PC25 // Pin 5 on the Arduino Due Board
#define LCD_RST PIO_PC24 // Pin 6 on the Arduino Due Board
#define LCD_DC PIO_PC23 // Pin 7 on the Arduino Due Board
#define LCD_DIN PIO_PC22 // Pin 8 on the Arduino Due Board
#define LCD_CLK PIO_PC21 // Pin 9 on the Arduino Due Board

#endif

#define LCD_CONTRAST 0x40

/*
 * Must be called once before any other function, initializes display
 */
void nokia_lcd_init(void);

/*
 * Clear screen
 */
void nokia_lcd_clear(void);

/**
 * Power of display
 * @lcd: lcd nokia struct
 * @on: 1 - on; 0 - off;
 */
void nokia_lcd_power(uint8_t on);

/**
 * Set single pixel
 * @x: horizontal pozition
 * @y: vertical position
 * @value: show/hide pixel
 */
void nokia_lcd_set_pixel(uint8_t x, uint8_t y, uint8_t value);

/**
 * Draw single char with 1-6 scale
 * @code: char code
 * @scale: size of char
 */
void nokia_lcd_write_char(char code, uint8_t scale);

/**
 * Draw string. Example: writeString("abc",3);
 * @str: sending string
 * @scale: size of text
 */
void nokia_lcd_write_string(const char *str, uint8_t scale);

/**
 * Set cursor position
 * @x: horizontal position
 * @y: vertical position
 */
void nokia_lcd_set_cursor(uint8_t x, uint8_t y);

/*
 * Render screen to display
 */
void nokia_lcd_render(void);

#ifdef __cplusplus
}
#endif
