//2-D ARRAY USING POINTER ARRAY
#include<stdio.h>

void main()
{
int *p[2];//int *p[no. of rows]
//suppose the 2-D array is known;
int c[2][3] = {{1,2,3},{4,5,6}};
p[0] = c[0];
p[1] = c[1];
for(int i = 0; i<2; i++)
{
   for(int j=0; j<3; j++)
{
    printf("%d",*(*(p+i)+j));
}
    printf("\n");
}

}
