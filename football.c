#include "football.h"
#include <stdio.h>

int count_combinations(int points) {
    int count = 0; // tracks the number of valid combinations

    // Iterate through all possible numbers of each type of scoring play
    for (int td_2pt = 0; td_2pt * 8 <= points; td_2pt++) { // TD + 2pt conversion
        for (int td_fg = 0; td_fg * 7 <= points; td_fg++) { // TD + FG
            for (int td = 0; td * 6 <= points; td++) { // Regular TD
                for (int fg = 0; fg * 3 <= points; fg++) { // Field Goal
                    for (int safety = 0; safety * 2 <= points; safety++) { // Safety
                        // Check if the sum of all scoring plays equals the given score
                        if (td_2pt * 8 + td_fg * 7 + td * 6 + fg * 3 + safety * 2 == points) {
                            // Print the valid combination
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                   td_2pt, td_fg, td, fg, safety);
                            count++;
                        }
                    }
                }
            }
        }
    }
    return count; // Returns the number of combos found
}

void print_combinations(int points) {
    printf("possible combinations of scoring plays if a team's score is %d: \n", points);
    int combinations = count_combinations(points);

    if (combinations == 0) {
        printf("no valid scoring combinations found.");
    }
    
}