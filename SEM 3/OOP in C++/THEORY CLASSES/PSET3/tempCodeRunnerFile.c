#include <stdio.h>
int main() {
    int myarray[] = {2, 4, 6, 8, 10, 12, 14};
    int size = 7;
    int key = 10,found = 0; //key is the element to be searched here

    printf("Array: ");
    for(int i = 0; i < size; i++)
        printf("%d ", myarray[i]);
    printf("\n");

    //LINEAR SEARCH
    for(int i = 0; i < size; i++) {
        if(myarray[i] == key) {
            found = i; // store index if found
            break;
        }
    }
    if(found != -1)
        printf("Linear Search: Element %d found at index %d\n", key, found);
    else
        printf("Linear Search: Element not found\n");

    // BINARY SEARCH
    int low = 0, high = size - 1, mid;
    found = -1; // reset flag
    while(low <= high) {
        mid = (low + high) / 2;
        if(myarray[mid] == key) {
            found = mid;
            break;
        } else if(myarray[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if(found != -1)
        printf("Binary Search: Element %d found at index %d\n", key, found);
    else
        printf("Binary Search: Element not found\n");

    return 0;
}
