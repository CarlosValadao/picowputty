#ifndef RGB_H
#define RGB_H

#include "pico/stdlib.h"

/** 
 * @file rgb.h
 * @brief Este arquivo contém declarações de funções e definições relacionadas a um
 *        LED RGB conectado aos pinos GPIO
 *
 * @author Carlos Valadao
 * @date 17/01/2025
 */

typedef struct
{
    uint red;
    uint green;
    uint blue;
} rgbpins;


void rgb_init(const rgbpins *pins);
void rgb_turn_on_red(const rgbpins *pins);
void rgb_turn_off_red(const rgbpins *pins);
void rgb_turn_on_green(const rgbpins *pins);
void rgb_turn_off_green(const rgbpins *pins);
void rgb_turn_on_blue(const rgbpins *pins);
void rgb_turn_off_blue(const rgbpins *pins);
void rgb_turn_on_white(const rgbpins *pins);
void rgb_turn_off_white(const rgbpins *pins);
void rgb_blink(const rgbpins *pins);

#endif