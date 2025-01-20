#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "buzzer.h"
#include "rgb.h"


#define HOLD_UNTIL_RELEASED(key, keyboard) while(keyboard_get_pressed_key(keyboard) == (key))
#define BUZZER_PIN 28
#define BEEP_DURATION_MS 100

#define GPIO_VERDE 11
#define GPIO_AZUL 12
#define GPIO_VERMELHO 13
#define GPIO_BUZZER 21

int main()
{
    stdio_init_all();
    char buffer[1024];
    rgbpins ledpins = {13, 11, 12};
    rgb_init(&ledpins);
    buzzer_init(BUZZER_PIN);
    while (true)
    {
        scanf("%1024s", buffer);
        if(strcmp(buffer, "R") == 0) rgb_turn_on_red(&ledpins);
        else if(strcmp(buffer, "G") == 0) rgb_turn_on_green(&ledpins);
        else if(strcmp(buffer, "B") == 0) rgb_turn_on_blue(&ledpins);
        else if(strcmp(buffer, "W") == 0) rgb_turn_on_white(&ledpins);
        else if(strcmp(buffer, "W") == 0) rgb_turn_on_white(&ledpins);
        else if(strcmp(buffer, "O") == 0) rgb_turn_off_white(&ledpins);
        else if(strcmp(buffer, "Z") == 0) buzzer_beep(BUZZER_PIN, BEEP_DURATION_MS);
        sleep_ms(100);
    }

    return 0;
}