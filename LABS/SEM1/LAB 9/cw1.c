/*
#include<stdio.h>
void display(int *a, int size);
void main()
{
    int a[5] = {1,2,3,4,5};
    int size = 5;
    display(&a,size); //here we are calling the entire array
}

void display(int *a,int size) // we input only reference as we take pointer as a parameter/argument
{
for(int i = 0; i < size; i++)
    printf("%d",*(a+i));

}
// 1.write a program to add the elements of an array using pointer. (find sum) pass the entire array in the function.
// 2. write a program to convert lowercase into uppercase and uppercase into lowercase for a string using pointer.
// 3. write a program to add the diagonal elements of a two-dimensional array.

*/

#include<stdio.h>
int summation(int *a,int size)
{
    int sum = 0 ; //variable stores the final sum
    for (int i = 0; i<size; i++)
        sum += *(a+i); //traversing across the array and adding each element to sum
    return sum; //back to main

}
void main()
{
    int a[5] = {1,2,3,4,5}; //initializing the array
    int size = 5;
    int sum = summation(&a,size); //calling the sum function
    printf("The sum of all number of the array is : %d",sum);
}
