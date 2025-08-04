//structure is a non-primitve data type 

#include<stdio.h>
#include<string.h>

void main(void)
{
    struct student
    {
        int roll; 
        char name[10]; 
        float marks; 

    }s1 ; 

    struct student s2; 
    //use dot operator to access elmenets: 
    s1.roll = 1; 
    //for name you have to initialize using strcpy
    strcpy(s1.name,"Kunj Shah");

    //array of students

    struct student slist[2];
    for(int i =0;i<2;i++)
    {
        int r; 
        char name[10];
        printf("Enter roll number: "); 
        scanf("%d",&r); 
        slist[i].roll = r; 
        printf("Enter name: "); 
        scanf("%s",&name);
        strcpy(slist[i].name,name); 
        float marks; 
        printf("Enter marks:"); 
        scanf("%f",&marks); 
        slist[i].marks = marks; 
    }
    for(int i = 0;i<2;i++)
    {
        printf("The marks of student %d named %s is %.2f \n",slist[i].roll,slist[i].name,slist[i].marks);
    }
    
    
}