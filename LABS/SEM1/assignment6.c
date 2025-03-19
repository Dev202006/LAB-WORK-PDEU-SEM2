
#include<stdio.h>
int main()
{
/*
Write a program to calculate and display a student's grade based on their scores in a course.
*/

int i;
printf("Enter your score: ");
scanf(" %d",&i);
if ( i>= 90)
    printf("Grade A");
else if (i>=80)
    printf("Grade B");
else if(i>=70)
    printf("Grade C");
else if (i>=60)
    printf("Grade D");
else
    printf("You Failed!");

return 0;
}

