//Take 10 integers from the user and find: Largest and smallest element, Average of all elements, Count of even and odd numbers

#include<stdio.h>

int main(void)
{
    //taking in 5 integers (cuz i'm lazy to type 10 times)
    int intarray[5];
    for(int i=0;i<5; i++)
    {
        printf("Enter an integer: ");
        scanf("%d",&intarray[i]);
    }
    // smallest and largest definition
    int smol = intarray[0];
    int big = smol; 
    //sum and average definition; 
    int sum = 0; 
    float avg = 0.0 ; 
    //defining count of even and odd
    int even = 0; 
    int odd = even; 

    //one common loop because we like to save time

    for(int i =0;i<5;i++)
    {
        // max and min
        int element = intarray[i];
        if (element>big)
        {
            big = element;
        }
        else if (element<smol)
        {
            smol = element; 
        }
        // odd and even 
        if (element%2 == 0)
        {
            even = even + 1; 
        }
        else
        {
            odd = odd + 1; 
        }
        // sum and average
        sum = sum + element; 

    }
    avg = sum/5; 
    
    //printing the analysis
    printf("Here's the analysis of the numbers: \n");
    printf("Minimum: %d and Maximum: %d\n Even numbers count: %d and Odd numbers count %d\n Sum %d and Average: %f",smol,big,even,odd,sum,avg);


}