#include<stdio.h>
void main(void)
{
    //initializing and assigning string with value from user
    char str[10];
    printf("Enter a string: ");
    fgets(str,sizeof(str),stdin);
    //referencing the string to a pointer
    char *p = str;
    //printing reverse string
    printf("\nprinting reverse string\n");
    for (int i = sizeof(str)-1; i>=0; i--)
        printf("%c",*(p+i));
}
