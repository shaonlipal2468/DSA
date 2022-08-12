#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>


//dequeue node
struct dequeue
{
  int rear;
  int front;
  int capacity;
  int *array;
};
//initialization
struct dequeue* creation()
{
  struct dequeue *q;
  q->capacity =10;
  q->front = q->rear = -1;
  q->array = (int *)malloc(q->capacity*sizeof(int));
  return q;
}

//queue is full or not
bool isFull(struct dequeue *q)
{
  if((q->front>q->rear) || ((q->front==0) && (q->rear ==q->capacity-1)))
    return true;
  return false;
}
//queue is empty or not
bool isEmpty(struct dequeue *q)
{
  if(q->front==-1)
    return true;
  return false;
}
//enqueue from front

void enqueue_front(struct dequeue *q,int data)
{
  if(isFull(q))
    printf("Overflow\n");
  else if(q->front==-1 && q->rear==-1)
  {
     q->front=q->rear=0;
     q->array[q->front]=data;

  }
  else if(q->front ==0)
  {
    q->front = q->capacity -1;
    q->array[q->front]= data;
  }
  else
  {
    q->front--;
    q->array[q->front]= data;
  }
//  printf("hiii %d\n",q->array[q->front]);
}
//enqueue from rear
void enqueue_rear(struct dequeue *q,int data )
{
  if(isFull(q))
    printf("Overflow\n");
  else if(q->front==-1 && q->rear==-1)
       q->front=q->rear=0;
  else if(q->rear == q->capacity-1)
    q->rear=0;
  else
     q->rear++;
  q->array[q->rear]=data;
  //printf("hiii %d\n",q->array[q->rear]);
}
//dequeue from front
int dequeue_front(struct dequeue *q)
{
  int data;
  if(isEmpty(q))
  {
    printf("Underflow\n");
    return -1;
  }
  data = q->array[q->front];
  if(q->front == q->rear)  //only one element
        q->front = q->rear = -1;
  else if(q->front ==q->capacity-1)
        q->front=0;
  else
     q->front++;
  return data;
}
//dequeue from rear end
int dequeue_rear(struct dequeue *q)
{
  int data;
  if(isEmpty(q))
  {
    printf("Underflow\n");
    return -1;
  }
  data = q->array[q->rear];
  if(q->front == q->rear)  //only one element
        q->front = q->rear = -1;
  else if(q->rear==0)
     q->rear = q->capacity-1;
  else
     q->rear--;
  return data;

}
//main function
int main()
{
    int choice,data,temp;
    struct dequeue *q=creation();
    while(1)
    {
        printf("*************************************\n");
        printf("1.enqueue data at front\n");
        printf("2.enqueue data at rear\n");
        printf("3.dequeue data from front\n");
        printf("4.dequeue data from rear\n");
        printf("5.Exit\n");
        printf("enter your choice \n");
        scanf("%d",&choice );
        switch(choice)
        {
            case 1:
                    printf("enter your data \n");
                    scanf("%d",&data );
                    enqueue_front(q,data);
                    break;
           case 2:
                    printf("enter your data \n");
                    scanf("%d",&data );
                    enqueue_rear(q,data);
                   break;
            case 3:
                    temp = dequeue_front(q);
                    if(temp!=-1)
                       printf("Dequed element is %d\n",temp);
                    break;
            case 4:
                   temp = dequeue_rear(q);
                   if(temp!=-1)
                       printf("Dequed element is %d\n",temp);
                   break;
            case 5:
                    exit(0);

            default:
                    printf("wrong choice\n");
                    break;
        }
    }
}
