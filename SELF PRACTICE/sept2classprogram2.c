#include<stdio.h>
// Program to add two matrices and print the resultant matrix
void main()
{
    int matrix[3][3] = {1,2,3,4,5,6,7,8,9};
    int matrix2[3][3] = {9,8,7,6,5,4,3,2,1};
    int result[3][3];
    for (int i = 0; i <=2; i++)
    {
        for (int j = 0; j <=2; j++)
            result[i][j] = matrix[i][j] + matrix2[i][j];
    }

    for (int i = 0; i <=2; i++)
    {
        for (int j = 0; j <=2; j++)
            printf("%d\t",result[i][j]);
        printf("\n");

    }

}
