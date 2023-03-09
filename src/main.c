
#include <stdio.h>

#include "pico/stdlib.h"
#include "pico/stdio.h"

int main() {

    stdio_init_all();

    // Set all of the pins to output
    for(int i = 0; i < 30; i++) {
        gpio_init(i);
        gpio_set_dir(i, GPIO_OUT);
    }

    bool isOn = true;
    uint8_t direction = 1;

    while(true) {
        printf("Hellorld!\n");

        if(isOn) {
            direction = 1;
        }
        else {
            direction = 0;
        }
        for(int i = 0; i < 30; i++) {
            gpio_put(i, direction);
        }

        isOn = !isOn;

        sleep_ms(500);
    }



    return 1;

}