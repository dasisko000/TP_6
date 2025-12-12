#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("01.input", "r"); 
    if (!file) {
        perror("Erreur ouverture fichier");
        return 1;
    }

    int position = 50;
    int count_zero = 0;
    char line[100];

    while (fgets(line, sizeof(line), file)) {
        char direction;
        int distance;

        if (sscanf(line, "%c%d", &direction, &distance) != 2) {
            continue; 
        }

        if (direction == 'R') {
            position = (position + distance) % 100;
        } else if (direction == 'L') {
            position = (position - distance + 100) % 100;
        }

        if (position == 0) {
            count_zero++;
        }
    }

    fclose(file);

    printf("Nombre de fois que le cadran pointe sur 0 : %d\n", count_zero);
    return 0;
}