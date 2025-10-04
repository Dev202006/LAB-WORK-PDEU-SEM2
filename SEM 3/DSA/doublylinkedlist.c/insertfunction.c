#include <stdio.h>
#include<stdlib.h>
struct node{
        int data; 
        struct node * prev; 
        struct node * next; 
    };

struct node* getnode()
{
    struct node *n1 = (struct node*)malloc(sizeof(struct node));
    n1->prev = NULL;
    n1->next = NULL; 
    n1->data = 0; 
    return n1; 
}

void setnode(struct node* first,struct node* second)
{
    first->next = second; 
    second->prev = first; 
}

void traversefwd(struct node *start)
{
    struct node * temp = start;
    while(temp!=NULL)
    {
        printf("The data in this node is: %d \n",temp->data );
        temp = temp->next; 
    }
}

int main() {

    struct node *p1 = getnode();
    p1->data = 10; 
    
    struct node *p2 = getnode();
    p2->data = 20; 

    struct node *p3 = getnode();
    p3->data = 30; 



    //insert right side and insert left side of p2; 
    
    /*p2->next = p3; 
    p3->prev =p2; 
    p2->prev = p1; 
    p1->next = p2; */

    struct node *p4 = getnode();
    p4->data = 40; 

    setnode(p2,p3);
    setnode(p1,p2);
    setnode(p3,p4);
    traversefwd(p1);
    
    printf("%d is the data",p3->next->data);
    return 0;
}