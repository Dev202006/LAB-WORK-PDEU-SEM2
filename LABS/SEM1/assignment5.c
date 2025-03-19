#include<stdio.h>
int main()
{
/*Write a C program that takes a character representing a grade ('A','B','C','D','E','F')
and prints the corresponding description using a  switch statement

*/
char c; //initialization of variable
printf("Enter the grade: ");
scanf("%c",&c); //inputting data

switch (c)
{
    case 'A':
        printf("Excellent!");
        break;
    case 'B':
        printf("Great!");
        break;
    case 'C':
        printf("Good!");
        break;
    case 'D':
        printf("Try harder!");
        break;
    case 'E':
        printf("Sorry you failed!");
        break;
    case 'F':
        printf("You failed badly. You have to try harder!");
        break;
}
}

