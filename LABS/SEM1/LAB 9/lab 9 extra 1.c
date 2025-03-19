#include<stdio.h>

void main()
{
    int a[2][3] = {{1,2,3},{4,5,6}};
    int *p_a = a;
    int rows = 2 , columns = 3;
    for(int row =0; row < rows; row++)
    {
        for(int column=0; column < columns; column ++)
            printf("The element (%d,%d) is %d \n",row+1,column+1,*(p_a+columns*row + column));
    }
}
