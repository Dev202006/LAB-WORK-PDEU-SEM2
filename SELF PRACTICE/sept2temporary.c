#include<stdio.h>
void main()
{
int i, j;
int stud[4][2] = {{1,2},{3,4},{5,6},{5,6}};

int weird[2][3] = {1,2,3,4,5,6};
int weird2[2][3] = {1,2,3,4,5,6};
for (i=0;i<=3;i++)
    {
        for(j=0;j<=1;j++)
        {

            printf("%d \t",stud[i][j]);

        }
        printf("\n");
    }
printf("new array\n");
for (i=0;i<=1;i++)
    {
        for(j=0;j<=2;j++)
        {

            printf("%d \t",weird[i][j]);

        }
        printf("\n");
    }
printf("new array");
for (i=0;i<=1;i++)
    {
        for(j=0;j<=2;j++)
        {

            printf("%d \t",weird2[i][j]);

        }
        printf("\n");
    }
}

