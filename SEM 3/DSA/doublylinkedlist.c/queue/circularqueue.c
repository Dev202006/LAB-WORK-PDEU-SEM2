//
#include <stdio.h>

#define SIZE 5
int rear = -1; 
int front = -1; 
int queue[SIZE];

void enqueue(int element)
{
    //check overflow
    if (front == (rear + 1) % SIZE)
    {
        printf("Overflow Error!");
        return; 
    }
        
    else
    {
        if(front ==-1)
            front=0; 
        rear = (rear + 1) % SIZE; 
        queue[rear] =element; 
        printf("Element %d Successfully Enqueued!\n",element);
    }

}


void dequeue()
{
    //check underflow
    if(front ==-1)
    {
        printf("Underflow Error!\n");
        return;
    }
    else
    {
        printf("%d dequeued\n",queue[front]);
        front = (front + 1) % SIZE;
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