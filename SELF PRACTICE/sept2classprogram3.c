//Find duplicates in an array (95% Kunj Brain)
#include<stdio.h>

void main()
{
int count = 0 ;
int originals[] = {};
int array[10] = {1,3,9,6,3,3,1,9,6,8} ;
for(int i = 0; i<10; i++)
{
       for (int j = i+1; j<10; j++)
    {
        if (array[i] == array[j])
            printf("Duplicate letter found: %d \n",array[j]);
    }
}



}
