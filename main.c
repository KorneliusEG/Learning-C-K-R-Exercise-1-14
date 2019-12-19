#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c;
    int char_array[100];
    int total_char_number = 0;
    int max_height = 0;
    int i, j;

    // Initializing main array with all counted characters
    for (i = 0; i <= 100; i++){
        char_array[i] = 0;
    }

    // Getting input and counting characters
    while((c = getchar()) != EOF){
        printf("c = %d\n", c);

        if (c == '\n') {
            char_array[95]++;
        } else if (c == '\t') {
            char_array[96]++;
        } else {
            char_array[c - 32]++;
        }
        total_char_number++;
    }

    // Calculating the most frequent character
    for (i = 0; i <= 96; i++) {
        if (char_array[i] > max_height) {
            max_height = char_array[i];
        }
    }

    // Drawing histogram
    for (j = max_height; j >= 0; j--) {
        putchar(j + '0');
        putchar(' ');
        for (i = 0; i < 48; i++) {
            if (j != 0) {
                if ((char_array[i] - j) >= 0) {
                    putchar(177);
                    putchar(' ');
                } else {
                    putchar(' ');
                    putchar(' ');
                }
            } else {
                putchar(i + 32);
                putchar(' ');
            }
        }
        putchar('\n');
    }
    // We divide our histogram into 2 parts for better appearance
    putchar('\n');
    for (j = max_height; j >= 0; j--) {
        putchar(j + '0');
        putchar(' ');
        for (i = 48; i <= 96; i++) {
            if (j != 0) {
                if ((char_array[i] - j) >= 0) {
                    putchar(177);
                    putchar(' ');
                } else {
                    putchar(' ');
                    putchar(' ');
                }
            } else {
                if (i == 95) {
                    putchar('\\');
                    putchar('n');
                } else if (i == 96) {
                    putchar('\\');
                    putchar('t');
                } else {
                    putchar(i + 32);
                    putchar(' ');
                }

            }
        }
        putchar('\n');
    }


    for (i = 0; i <= 96; i++){
        if (char_array[i] > 0){
            putchar(i + 32);
            putchar(':');
            putchar(char_array[i] + '0');
            putchar('\n');
        }
        //printf("char_array[%d] = %d\n", i, char_array[i]);
    }

    return 0;
}
