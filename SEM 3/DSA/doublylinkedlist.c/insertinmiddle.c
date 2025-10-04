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
//inserts after the node that has the data
void insertmiddle(struct node * start, int x, struct node *new)
{
    struct node * temp = start;
    while (temp!=NULL)
    {
        if (temp->data == x)
            break; 
        temp = temp->next; 
    }
    if(temp)
    {
        temp->next->prev = new;
        new->next = temp->next;
        new->prev = temp;
        temp->next = new; 
    }
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
    p3->data = 40; 

    struct node *p4 = getnode();
    p4->data = 30; 

    struct node *start = p1; 
    setnode(p2,p3);
    setnode(p1,p2);
    insertmiddle(start,20,p4);
    struct node * p5 = getnode();
    p5->data = 2; 
    insertmiddle(start,30,p5);  
traversefwd(start);
    
    return 0;
}