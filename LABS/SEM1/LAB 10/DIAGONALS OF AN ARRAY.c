//2-D ARRAY USING POINTER ARRAY
#include<stdio.h>

void main()
{
int *p[3];//int *p[no. of rows]
//suppose the 2-D array is known;
int c[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
p[0] = c[0];
p[1] = c[1];
p[2] = c[2];
for(int j=0; j<3; j++)
{
    printf("%d",*(*(p+j)+j));

}
    printf("\n");
}

