#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
//circular queue node
struct circular_queue
{
  int rear;
  int front;
  int capacity;
  int *array;
};
//initialization
struct circular_queue* creation()
{
  struct circular_queue *q;
  q->capacity =100;
  q->front = q->rear = -1;
  q->array = (int *)malloc(q->capacity*sizeof(int));
  return q;
}
//queue is full or not
bool isFull(struct circular_queue *q)
{
  if(((q->rear+1)%q->capacity)==q->front)
    return true;
  return false;
}
//queue is empty or not
bool isEmpty(struct circular_queue *q)
{
  if(q->rear==-1 && q->front==-1)
    return true;
  return false;
}
//enqueue element at rear end
void enqueue(struct circular_queue *q,int data)
{
  if(isFull(q))
    printf("Overflow\n");
  if(q->front ==-1 && q->rear ==-1)
        q->front = q->rear=0;
  else
        q->rear = (q->rear+1)%q->capacity;
  q->array[q->rear]=data;
}
//dequeue element from front end
int dequeue(struct circular_queue *q)
{
  if(isEmpty(q))
    {
      printf("underflow\n");
      return -1;
    }
  int temp = q->array[q->front];
  if(q->front==q->rear)
     q->front=q->rear =-1;
  else
     q->front = (q->front+1)%q->capacity;

     return temp;
}
//main function
int main()
{
    int choice,data,temp;
    struct circular_queue *q=creation();
    while(1)
    {
        printf("*************************************\n");
        printf("1.enqueue data\n");
        printf("2.dequeue data\n");
        printf("3.Exit\n");
        printf("enter your choice \n");
        scanf("%d",&choice );
        switch(choice)
        {
            case 1:
                    printf("enter your data \n");
                    scanf("%d",&data );
                    enqueue(q,data);
                    break;
            case 2:
                    temp = dequeue(q);
                    if(temp!=-1)
                       printf("Dequed element is %d\n",temp);
                    break;
            case 3:
                    exit(0);
            default:
                    printf("wrong choice\n");
                    break;
        }
    }
}
