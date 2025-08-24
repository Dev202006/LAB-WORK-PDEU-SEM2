#include <stdio.h>

int main() {
    int arr1[] = {64, 25, 12, 22, 11};
    int arr2[] = {64, 25, 12, 22, 11};
    int arr3[] = {64, 25, 12, 22, 11};
    int size = 5;
    int i, j, temp;

    printf("Original Array: ");
    for(i = 0; i < size; i++) printf("%d ", arr1[i]);
    printf("\n");

    //BUBBLE SORT
    for(i = 0; i < size - 1; i++) {
        for(j = 0; j < size - i - 1; j++) {
            if(arr1[j] > arr1[j+1]) {
                temp = arr1[j];
                arr1[j] = arr1[j+1];
                arr1[j+1] = temp;
            }
        }
    }
    printf("After Bubble Sort: ");
    for(i = 0; i < size; i++) printf("%d ", arr1[i]);
    printf("\n");

    // INSERTION SORT
    for(i = 1; i < size; i++) {
        temp = arr2[i];
        j = i - 1;
        while(j >= 0 && arr2[j] > temp) {
            arr2[j+1] = arr2[j];
            j--;
        }
        arr2[j+1] = temp;
    }
    printf("After Insertion Sort: ");
    for(i = 0; i < size; i++) printf("%d ", arr2[i]);
    printf("\n");

    // SELECTION SORT
    for(i = 0; i < size - 1; i++) {
        int minIndex = i;
        for(j = i + 1; j < size; j++) {
            if(arr3[j] < arr3[minIndex])
                minIndex = j;
        }
        if(minIndex != i) {
            temp = arr3[i];
            arr3[i] = arr3[minIndex];
            arr3[minIndex] = temp;
        }
    }
    printf("After Selection Sort: ");
    for(i = 0; i < size; i++) printf("%d ", arr3[i]);
    printf("\n");

    return 0;
}
