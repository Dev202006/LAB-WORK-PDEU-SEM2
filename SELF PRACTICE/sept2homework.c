#include <stdio.h>
void main()
{
    int array[5] = {1,2,3,4,5};
    int temp; 
    for (int i = 0; i<= 5/2;i++)
    {
        temp = array[i]; 
        array[i] = array[4-i]; 
        array[4-i] = temp; 

    }
    for (int i = 0; i< 5;i++)
    {
        printf("%d ",array[i]); 
        
    }

}