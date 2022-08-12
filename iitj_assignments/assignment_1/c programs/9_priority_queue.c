//LOWER THE VALUE HIGHER THE PRIORITY
#include<stdio.h>
#include<stdlib.h>
//priority queue node
struct node{
	int data;
  int priority;
	struct node *next;
};
//make new node
struct node *make_new_node(int data,int priority)
{
        struct node *newnode = NULL;
	      newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->priority= priority;
        newnode->next=NULL;
        return newnode;
}
//queue is empty or not
int isEmpty(struct node *front)
{
  if(front==NULL)
    return 1;
  return 0;
}
//display queue
void display(struct node *front)
{
  if(isEmpty(front))
     {
       printf("Priority queue is empty\n");
       return;
     }
  struct node *temp=front;
  printf("Priority    : Item\n");
  while(temp!=NULL)
  {
      printf("%4d    %8d\n ",temp->priority,temp->data);
      temp = temp->next;
  }
}


struct node * insert(struct node *front,int data,int prio)
{
    struct node *newnode = make_new_node(data,prio);
    //if queue is empty or coming priority is less than front priority, then node will
    //added at start position
    if(isEmpty(front) || prio<front->priority )
    {
      newnode->next = front;
      front= newnode;
    }
    //elements will be sorted in order of priority, find the right place for coming item
    else
    {
       struct node *temp= front;
       while(temp->next!=NULL && temp->next->priority<=prio)
          temp = temp->next;
       newnode->next = temp->next;
       temp->next = newnode;
    }
    return front;


}
//delete min element
struct node * delete_(struct node *front)
{
  struct node *temp;
  int data;
  if(isEmpty(front))
    {
      printf("Underflow\n");
      data =-1;
    }

  else
  {
    temp =front;
    data = temp->data;
    front = front->next;
    free(temp);
  }
  if(data!=-1)
     printf("deleted element is %d\n",data);
  return front;
}

void print_menu()
{
   printf("1.INSERT\n");
   printf("2.DELETE\n");
   printf("3.DISPLAY\n");
   printf("4.EXIT\n");
   printf("enter your choice :\n");

}
//main function
int main()
{
  printf("********************S T A R T***********************\n");
  int choice,data,priority;
	struct node *front = NULL;
  while(1)
  {
    printf("**************************************************\n");
    print_menu();
    scanf("%d",&choice);
    switch(choice)
    {
       case 1:
            printf("enter data :\n");
            scanf("%d",&data);
            printf("enter priority :\n");
            scanf("%d",&priority);
            front = insert(front,data,priority);
            display(front);
            break;

       case 2:
               front = delete_(front);
               display(front);
               break;

       case 3:
               display(front);
               break;
       case 4:
               exit(0);
       default:
                printf("wrong choice\n");
                break;
    }
  }

}
