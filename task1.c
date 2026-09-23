#include <stdio.h>

void findCombinations(int score) {
    printf("Possible combinations of scoring plays if a team's score is %d:\n", score);
    int found = 0;

    for (int a = 0; a * 8 <= score; a++) {           // TD + 2pt (8)
        for (int b = 0; a * 8 + b * 7 <= score; b++) { // TD + FG (7)
            for (int c = 0; a * 8 + b * 7 + c * 6 <= score; c++) { // TD (6)
                for (int d = 0; a * 8 + b * 7 + c * 6 + d * 3 <= score; d++) { // FG (3)
                    int remaining = score - (a * 8 + b * 7 + c * 6 + d * 3);
                    if (remaining >= 0 && remaining % 2 == 0) {
                        int safety = remaining / 2; // Safety (2)
                        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                               a, b, c, d, safety);
                        found = 1;
                    }
                }
            }
        }
    }

    if (!found) {
        printf("No possible combinations.\n");
    }
}

int main(void) {
    int score;

    while (1) {
        printf("Enter the NFL score (Enter 1 to stop): ");
        if (scanf("%d", &score) != 1) {
            printf("Invalid input.\n");
            while (getchar() != '\n'); // clear bad input
            continue;
        }

        if (score == 1) {
            break;
        }

        if (score < 0) {
            printf("Invalid score: score cannot be negative.\n");
            continue;
        }

        findCombinations(score);
    }

    return 0;
}
