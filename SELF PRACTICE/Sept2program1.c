
#include<stdio.h>

void main()
{
    int stud[4][2];
    int i,j;
    for (i=0;i<=3;i++)
    {
        for(j=0;j<=1;j++)
        {
            if (j==0)
            {
             printf("Enter roll no: ");
            }

            else
                printf("Enter marks: ");
            scanf("%d",&stud[i][j]);
        }

    }
    for (i=0;i<=3;i++)
    {
        for(j=0;j<=1;j++)
        {

            printf("%d \t",stud[i][j]);

        }
        printf("\n");

    }

}

