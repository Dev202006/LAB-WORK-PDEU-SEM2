#include <stdio.h>
#include <limits.h> // for INT_MAX, INT_MIN

int main() {
    int arr[] = {15, 7, 22, 3, 45, 18};
    int size = 6; 
    int i;
    int min = arr[0], max = arr[0];
    int secondMin = min, secondMax = max;

    printf("Array: ");
    for(i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

    // First pass: Find min and max
    for(i = 1; i < size; i++) {
        if(arr[i] < min) min = arr[i];
        if(arr[i] > max) max = arr[i];
    }

    // Second time running programme: Find second min and second max (as discussed in Viva)
    for(i = 0; i < size; i++) {
        if(arr[i] != min && arr[i] < secondMin)
            secondMin = arr[i]; 
        if(arr[i] != max && arr[i] > secondMax)
            secondMax = arr[i];
    }

    printf("Minimum Element: %d\n", min);
    printf("Maximum Element: %d\n", max);
    printf("Second Minimum Element: %d\n", secondMin);
    printf("Second Maximum Element: %d\n", secondMax);

    return 0;
}
