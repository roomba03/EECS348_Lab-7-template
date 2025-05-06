#include "football.h"
#include <stdio.h>
#include <stdlib.h> // For atoi()

int main(int argc, char *argv[]) {
    int score;

    if (argc > 1) {
        score = atoi(argv[1]); // Convert command-line argument to integer
        if (score > 1) {
            print_combinations(score); // Process the score
        } else {
            printf("Program terminated.\n");
            return 0;
        }
    }

    while (1) {
        printf("Enter the NFL score (0 or 1 to STOP): ");

        if (scanf("%d", &score) != 1) {
            printf("Invalid input. Please enter a valid integer.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        if (score <= 1) {
            printf("Program terminated.\n");
            break;
        }

        print_combinations(score);
    }
    
    return 0;
}

