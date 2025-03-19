/*
Write a C program to display the salary of a school teacher working in Jonson Public School along with related details. To display the salary, the user must input the class they are instructing, their qualification, and the total years of service. The qualification is inputted as an integer value where 0 is for Graduate and 1 is for Post Graduate. The salary will be calculated as the matrix given below:

Class | Years of Service | Qualifications | Salary

>8 | ≥ 10 | Post Graduate | 15000
>8 | ≥ 10 | Graduate | 10000
>8 | < 10 | Post Graduate | 11000
>8 | < 10 | Graduate | 7000
≤ 8 | ≥ 10 | Post Graduate | 12000
≤ 8 | ≥ 10 | Graduate | 9000
≤ 8 | < 10 | Post Graduate | 10000
≤ 8 | < 10 | Graduate | 6000

The output should display all the details about the person with appropriate messages for example:
The Class being taught is 9.
The qualification is Graduate.
The year of service is 3.
The salary is Rs. 7000.00.

*/

#include<stdio.h>
int main(void)
{
    //variable declaration
    int class,qual,serv;
    float salary ;

    //inputting value from the user
    printf("\nEnter the class taught in: ");
    scanf("%d",&class);
    printf("\nEnter the qualification (0 for graduate, 1 for post graduate): ");
    scanf("%d",&qual);
    printf("\nEnter the service period in years: ");
    scanf("%d",&serv);


    //evaluating salary based on conditions
    if (class>8)
    {
        if (serv>=10)
        {
            if(qual==1)
                salary = 15000;
            else
                salary = 10000 ;
        }
        else
        {
            if(qual==1)
                salary = 11000;
            else
                salary = 7000 ;
        }
    }
    else
    {
        if (serv>=10)
        {
            if(qual==1)
                salary = 12000;
            else
                salary = 9000 ;
        }
        else
        {
            if(qual==1)
                salary = 10000;
            else
                salary = 6000 ;
        }
    }

    //printing the output
    printf("\nThe class being taught in is %d",class);
    if (qual == 1)
        printf("\nThe qualification is %s","Post-Graduate");
    else
        printf("\nThe qualification is %s","Graduate");
    printf("\nThe years of service is %d",serv);
    printf("The salary is %.2f",salary);
    


}