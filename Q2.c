#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("01.input", "r");
    if (!file) {
        perror("Erreur ouverture fichier");
        return 1;
    }

    int position = 50;
    int count_end_zero = 0;      // Question 1 : fin sur 0
    int count_pass_zero = 0;     // Question 2 : passage par 0
    char line[100];

    while (fgets(line, sizeof(line), file)) {
        char direction;
        int distance;

        if (sscanf(line, "%c%d", &direction, &distance) != 2) {
            continue;
        }

        // Calculer le déplacement pas à pas pour détecter les passages par 0
        int step = (direction == 'R') ? 1 : -1;
        int current_pos = position;

        for (int i = 0; i < distance; i++) {
            current_pos = (current_pos + step + 100) % 100;
            if (current_pos == 0) {
                count_pass_zero++;
            }
        }

        position = current_pos;

        if (position == 0) {
            count_end_zero++;
        }
    }
        fclose(file);

    printf("Question 1: %d\n", count_end_zero);
    printf("Question 2: %d\n", count_pass_zero);

    return 0;
}