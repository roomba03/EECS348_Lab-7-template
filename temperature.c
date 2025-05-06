#include "temperature.h"
#include <stdio.h>

// C to F
float celsius_to_fahrenheit(float celcius) {
    return (9.0 / 5.0) * celcius + 32.0;
}

// F to C
float fahrenheit_to_celsius(float fahrenheit) {
    return (5.0 / 9.0) * fahrenheit - 32.0;
}

// C to K
float celsius_to_kelvin(float celcius) {
    return celcius + 273.15;
}

// K to C
float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

// categorizes temperatures
void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("category: freezing\nadvisory: wear warm clothes, stay indoors.\n");
    } else if (celsius >= 0 && celsius <= 10) {
        printf("category: cold\nadvisory: wear a jacket.\n");
    } else if (celsius > 10 && celsius <= 25) {
        printf("category: comfortable\nadvisory: go out and have fun!\n");
    } else if (celsius > 25 && celsius <= 35) {
        printf("category: hot\nadvisory: drink water to stay cool.\n");
    } else {
        printf("category: extreme heat\nadvisory: stay indoors to avoid the intense heat\n");
    }

}
