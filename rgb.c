#include "rgb.h"

void rgb_init(const rgbpins *pins)
{
    //Configuração de cada pino do LED como saída
    gpio_init(pins->red);
    gpio_set_dir(pins->red, GPIO_OUT);

    gpio_init(pins->green);
    gpio_set_dir(pins->green, GPIO_OUT);

    gpio_init(pins->blue);
    gpio_set_dir(pins->blue, GPIO_OUT);

    //Garantir que o LED RGB inicie desligado
    gpio_put(pins->red, 0);
    gpio_put(pins->green, 0);
    gpio_put(pins->blue, 0);
}

void rgb_turn_on_red(const rgbpins *pins)
{
    //Ligar o LED vermelho
    gpio_put(pins->red, 1);
    gpio_put(pins->green, 0);
    gpio_put(pins->blue, 0);
}

void rgb_turn_off_red(const rgbpins *pins)
{
    //Desligar o LED vermelho
    gpio_put(pins->red, 0);
}

void rgb_turn_on_green(const rgbpins *pins)
{
     //Ligar o LED Verde
    gpio_put(pins->green, 1);
    gpio_put(pins->red, 0);
    gpio_put(pins->blue, 0);
}

void rgb_turn_off_green(const rgbpins *pins)
{
     //Desligar o LED Verde
    gpio_put(pins->green, 0);
}

void rgb_turn_on_blue(const rgbpins *pins)
{
     //Ligar o LED azul
    gpio_put(pins->blue, 1);
    gpio_put(pins->red, 0);
    gpio_put(pins->green, 0);
}

void rgb_turn_off_blue(const rgbpins *pins)
{
    //Desligar o LED Azul
    gpio_put(pins->blue, 0);
}

void rgb_turn_on_white(const rgbpins *pins) {
    gpio_put(pins->red, 1);
    gpio_put(pins->green, 1);
    gpio_put(pins->blue, 1);
}

void rgb_turn_off_white(const rgbpins *pins) {
    gpio_put(pins->red, 0);
    gpio_put(pins->green, 0);
    gpio_put(pins->blue, 0);
}


void rgb_blink(const rgbpins *pins)
{
    return;
}
