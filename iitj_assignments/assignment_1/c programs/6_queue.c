#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
//queue node
struct queue
{
  int rear;
  int front;
  int capacity;
  int *array;
};

//initialzation
struct queue* creation()
{
  struct queue *q;
  q->capacity =100;
  q->front = q->rear = -1;
  q->array = (int *)malloc(q->capacity*sizeof(int));
  return q;
}
//queue is full or not
bool isFull(struct queue *q)
{
  if(q->rear==q->capacity-1)
    return true;
  return false;
}
//queue is empty or not
bool isEmpty(struct queue *q)
{
  if(q->rear+1==q->front || (q->rear==-1 && q->front==-1))
    return true;
  return false;
}
//enqueue element at rear end
void enqueue(struct queue *q,int data)
{
  if(isFull(q))
    printf("Overflow\n");
  if(q->front==-1 && q->rear==-1)
     q->front =0;

  q->array[++q->rear]=data;

}
//dequeue element from front end
int dequeue(struct queue *q)
{
  if(isEmpty(q))
    {
      printf("underflow\n");
      return -1;
    }
    int data = q->array[q->front];
  if(q->front == q->rear)
      q->front=q->rear =-1;
  else
  {
     q->front++;

  }
  return data;
}
//display queue
void display(struct queue *q)
{
  if(isEmpty(q))
      printf("underflow\n");
  else
  {
    printf("front\t");
    for(int i=q->front;i<=q->rear;i++)
       printf("%d\t",q->array[i]);
    printf("rear\n");
  }
}
//main function
int main()
{
    int choice,data,temp;
    struct queue *q=creation();
    while(1)
    {
        printf("*************************************\n");
        printf("1.enqueue data\n");
        printf("2.dequeue data\n");
        printf("3.display\n");
        printf("4.Exit\n");
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
                    display(q);
                    break;
            case 4:
                    exit(0);
            default:
                    printf("wrong choice\n");
                    break;
        }
    }
}
