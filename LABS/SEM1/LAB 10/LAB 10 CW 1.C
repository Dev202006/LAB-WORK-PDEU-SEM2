#include <stdio.h>

int main(void) {
    int *p[3];
    int c[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int sum = 0;


    p[0] = c[0];
    p[1] = c[1];
    p[2] = c[2];

    // Loop to sum the diagonal elements
    for (int i = 0; i < 3; i++) {
        sum += *(*(p + i) + i);
    }

    printf("Sum of diagonal elements: %d\n", sum);

    return 0;
}
