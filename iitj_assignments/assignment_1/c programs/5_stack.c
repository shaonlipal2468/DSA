#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
//stack node
struct stack
{
  int top;
  int capacity;
  int *array;
};

//Initialization
struct stack* creation()
{
  struct stack *s;
  s->capacity =100;
  s->top= -1;
  s->array = (int *)malloc(s->capacity*sizeof(int));
  return s;
}
//stack is full or not
bool isFull(struct stack *s)
{
  if(s->top==s->capacity-1)
    return true;
  return false;
}
//stack is empty or not
bool isEmpty(struct stack *s)
{
  if(s->top==-1)
    return true;
  return false;
}
//Pust element
void push(struct stack *s,int data)
{
  if(isFull(s))
    printf("Overflow\n");
  else
      s->array[++s->top]=data;

}
//pop element
int pop(struct stack *s)
{
  if(isEmpty(s))
    {
      printf("underflow\n");
      return -1;
    }
  else
     return s->array[s->top--];

}
//get top element
int getTop(struct stack *s)
{
  if(isEmpty(s))
    {
      printf("underflow\n");
      return -1;
    }
  else
  return s->array[s->top];
}
//display stack
void display(struct stack *s)
{
  if(isEmpty(s))
      printf("underflow\n");
  else
  {
    for(int i=0;i<=s->top;i++)
       printf("%d\t",s->array[i]);
    printf("\n");
  }
}
//main function
int main()
{
    int choice,data,temp;
    struct stack *s=NULL;
    s=creation();
    while(1)
    {
        printf("*************************************\n");
        printf("1.push data\n");
        printf("2.pop data\n");
        printf("3.display\n");
        printf("4.get top\n");
        printf("5.Exit\n");
        printf("enter your choice \n");
        scanf("%d",&choice );
        switch(choice)
        {
            case 1:
                    printf("enter your data \n");
                    scanf("%d",&data );
                    push(s,data);
                    break;
            case 2:
                    temp = pop(s);
                    if(temp!=-1)
                       printf("popped element is %d\n",temp);
                    break;
            case 3:
                   display(s);
                   break;
            case 4: printf("top element is  %d\n",getTop(s));
                    break;

            case 5:
                    exit(0);
            default:
                    printf("wrong choice\n");
                    break;
        }
    }
}
