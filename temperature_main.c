#include "temperature.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// converts from string to integer
int str_to_int(const char *str) {
    char *end;
    int value = strtol(str, &end, 10);
    if (*end != '\0') {
        return -1; // returns for invalid input
    }
    return value; // returns converted int
}

// makes sure the scale provided by the user is valid
int get_scale(const char *arg) {
    int scale = str_to_int(arg); // calls str_to_int
    if (scale < 1 || scale > 3) { // checks if the scale is valid
        return -1; // returns for invalid scale
    }
    return scale; // returns valid scale
}

int main(int argc, char *argv[]) {
    // printf("enter a temperature value\n");
    // printf("choose temperature scale of the input value (F, C, or K)\n");
    // printf("choose conversion target (F, C, or K)\n");

    float temp = atof(argv[1]); // converts temp value to a float

    int input_scale = get_scale(argv[2]); // gets input scale
    int output_scale = get_scale(argv[3]); // gets output scale

    // checks if scales are valid
    if (input_scale == -1 || output_scale == -1) {
        printf("invalid scale choice. use 1 for fahrenheit, 2 for celsius, or 3 for kelvin\n");
        return 1; // returns for invalid scale
    }

    // check if the input and output scales are the same
    if (input_scale == output_scale) {
        printf("the input scale and output scale are the same\n");
        return 1; // returns if the i/o scales are the same
    }
    
    float converted_temp = 0.0; // initialize variable that will store the converted temperature

    switch (input_scale) {
        case 1: // fahrenheit
            if (output_scale == 2) { // converts from F to C
                converted_temp = fahrenheit_to_celsius(temp);
            } else if (output_scale == 3) { // converts from F to K
                converted_temp = celsius_to_kelvin(fahrenheit_to_celsius(temp));
            }
            break;
        case 2: // celsius
            if (output_scale == 1) { // converts from C to F
                converted_temp = celsius_to_fahrenheit(temp);
            } else if (output_scale == 3) { // converts from Celsius to Kelvin
                converted_temp = celsius_to_kelvin(temp);
            }
            break;
        case 3: // kelvin
            if (output_scale == 1) { // converts from K to F
                converted_temp = celsius_to_fahrenheit(kelvin_to_celsius(temp));
            } else if (output_scale == 2) { // converts from K to C
                converted_temp = kelvin_to_celsius(temp);
            }
            break;
    }

    printf("converted temperature: %.2f\n", converted_temp); // print converted temp
    categorize_temperature(converted_temp);

    return 0;
}
