//Program to find the minimum or maximum element of an array

#include<stdio.h>

void main()
{
    int ar[5] = {1,1000,-1,33,44};
    int min = ar[0];
    int max = ar[0];
    for(int i = 0; i<5;i++)
    {
        if (ar[i]>=max)
            max = ar[i];
        if (ar[i]<=min)
            min = ar[i];
    }
    printf("The maximum is : %d",max);
    printf("The minimum is : %d",min);
}
