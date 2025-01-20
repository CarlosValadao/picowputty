#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define GPIO_VERDE 11
#define GPIO_AZUL 12
#define GPIO_VERMELHO 13
#define GPIO_BUZZER 21

void toLowerCase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower((unsigned char)str[i]);
    }
}

void play_tone(uint16_t frequency, uint duration_ms, uint pin)
{
    if (frequency > 0)
    {
        uint slice_num = pwm_gpio_to_slice_num(pin);
        pwm_set_wrap(slice_num, 125000000 / frequency - 1);
        pwm_set_gpio_level(pin, (125000000 / frequency) / 2);
        pwm_set_enabled(slice_num, true);
        sleep_ms(duration_ms);
    }
    else
    {
        pwm_set_enabled(pwm_gpio_to_slice_num(pin), false);
    }
}

void init_gpio()
{
    gpio_init(GPIO_VERMELHO);
    gpio_init(GPIO_VERDE);
    gpio_init(GPIO_AZUL);
    gpio_init(GPIO_BUZZER);

    gpio_set_dir(GPIO_VERMELHO, GPIO_OUT);
    gpio_set_dir(GPIO_VERDE, GPIO_OUT);
    gpio_set_dir(GPIO_AZUL, GPIO_OUT);
    gpio_set_dir(GPIO_BUZZER, GPIO_OUT);
    gpio_set_function(GPIO_BUZZER, GPIO_FUNC_PWM);
}

void execute(char * command) {
    toLowerCase(command);
    printf("COMMAND: %s!\n", command);
    if (strcmp(command, "red") == 0) {
        gpio_put(GPIO_VERMELHO, true);
        gpio_put(GPIO_AZUL, false);
        gpio_put(GPIO_VERDE, false);
    } else if (strcmp(command, "green") == 0) {
        gpio_put(GPIO_VERDE, true);
        gpio_put(GPIO_VERMELHO, false);
        gpio_put(GPIO_AZUL, false);
    } else if (strcmp(command, "blue") == 0) {
        gpio_put(GPIO_AZUL, true);
        gpio_put(GPIO_VERDE, false);
        gpio_put(GPIO_VERMELHO, false);
    } else if (strcmp(command, "white") == 0) {
        gpio_put(GPIO_AZUL, true);
        gpio_put(GPIO_VERDE, true);
        gpio_put(GPIO_VERMELHO, true);
    } else if (strcmp(command, "buzzer") == 0) {
        gpio_put(GPIO_AZUL, false);
        gpio_put(GPIO_VERDE, false);
        gpio_put(GPIO_VERMELHO, false);
        play_tone(2093, 2000, GPIO_BUZZER);
        play_tone(0, 0, GPIO_BUZZER);
    } else if (strcmp(command, "offled") == 0) {
        gpio_put(GPIO_AZUL, false);
        gpio_put(GPIO_VERDE, false);
        gpio_put(GPIO_VERMELHO, false);
    }else {
        printf("Unknown command\n\n");
        printf("Commands availables:\n- red\n- blue\n- green\n- white\n- buzzer\n- offled\n\n");
    }
}

int main()
{
    stdio_init_all();
    init_gpio();
    char buffer[1024];

    while (true)
    {
        scanf("%1024s", buffer);
        execute(buffer);
        sleep_ms(100);
    }

    return 0;
}