#include <stdio.h>

#define SIZE 5
int rear = -1; 
int front = -1; 
int queue[SIZE];

void enqueue(int element)
{
    //check overflow
    if (rear==SIZE-1)
    {
        printf("Overflow Error!");
        return; 
    }
        
    else
    {
        if(front ==-1)
            front=0; 
        rear++;
        queue[rear] =element; 
        printf("Element %d Successfully Enqueued!\n",element);
    }

}


void dequeue()
{
    //check underflow
    if(front ==-1 || front>rear)
    {
        printf("Underflow Error!\n");
        return;
    }
    else
    {
        printf("%d dequeued\n",queue[front]);
        front++;
    }


}



int main() {

    enqueue(3);
    enqueue(5);
    dequeue();
    enqueue(7);
    dequeue();


    
    return 0;
}