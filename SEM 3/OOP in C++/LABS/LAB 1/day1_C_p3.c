//Scan a number and check whether its a palindrome or not

#include<stdio.h>

void main(void)
{
    int x; 
    printf("Enter a number: "); 
    scanf("%d",&x); 

    //reversing the number
    int temp = x; 
    int new = 0; 
    while(temp)
    {
        new = new*10 + temp%10;
        temp = temp/10; 
    }
    if(new == x)
    {
        printf("%d is palindrome",x); 
    }
    else
        printf("%d is not palindrome",x); 
}