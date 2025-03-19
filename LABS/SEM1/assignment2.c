#include<stdio.h>
int main()
{
/*
Write a program that will scan and print integer , float and char variables.
*/

//Initialize 3 variables to store data
int i ;
float f;
char c;
char s[10];

//printing requests to user and receiving input from user
printf("Input an integer: ");
scanf("%d",&i);
printf("Input a float type literal: ");
scanf("%f",&f);
printf("Input a char type literal: ");
scanf(" %c",&c);
printf("Input a string type literal: ");
scanf(" %s",&s);

//Displaying the data inputted from the user
printf("The integer, float and char type data inputted was as follows: %d,%f,%c,%s",i,f,c,s);

}
