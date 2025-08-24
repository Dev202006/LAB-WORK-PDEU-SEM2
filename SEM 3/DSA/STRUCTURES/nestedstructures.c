#include<stdio.h>
#include<string.h>
struct organization
    {
        struct employee
        {
            char e_name[25]; 
            int e_id; 
        };
        struct employee e_array[4];
        char o_name[50];
        int o_id; 
    };


void main(void)
{
    struct organization manyorgs[2];
    for(int i=0;i<2;i++)
    {
        char o_name[50];
        printf("Enter name of organization: "); 
        scanf("%s",&o_name);
        strcpy(manyorgs[i].o_name,o_name);
        printf("Enter Organization id: ");
        scanf("%d",&manyorgs[i].o_id);
        printf("Now taking employee information \n\n");
        for(int j =0;j<4;j++)
        {
            printf("Enter id: ");
            scanf("%d",&manyorgs[i].e_array[j].e_id);
            char name[25]; 
            printf("Enter name: "); 
            scanf("%s",&manyorgs[i].e_array[j].e_name); 

        }
    }
    for(int i=0;i<2;i++)
    {
        printf("The name of the organization is: %s \n",manyorgs[i].o_name);
        printf("The organization id is: %d \n",manyorgs[i].o_id);
        printf("Now printing the employees...\n\n");
        for(int j =0;j<4;j++)
        {
            printf("Employee id is: %d for employee named %s\n",manyorgs[i].e_array[j].e_id,manyorgs[i].e_array[j].e_name);
        }
    }


}