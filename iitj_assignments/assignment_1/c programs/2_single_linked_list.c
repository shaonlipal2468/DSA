#include<stdio.h>
#include<stdlib.h>
//Linked list node
struct list{
	int data;
	struct list *next;
};

//creating one new node
struct list *make_new_node(int data)
{
        struct list *newnode = NULL;
	      newnode = (struct list *)malloc(sizeof(struct list));
        newnode->data = data;
        newnode->next=NULL;
        return newnode;
}

//function to find length of linked list
int length(struct list *head)
{
        int length= 0;
        if(head==NULL)
              return length;
        else
        {
             struct list *temp = head;
             while(temp!=NULL)
                  {
                       length+=1;
                       temp=temp->next;
                  }
             return length;
        }
}

//Function to insert node at the start of linked list
struct list *insert_at_head(struct list *head, int data)
{
  struct list *newnode = NULL;
  newnode = make_new_node(data);
	if(head == NULL)
		   head = newnode;
	else
	{
		newnode->next = head;
		head = newnode;
	}
	return head;
}
//Function to insert node at the end of linked list
struct list *insert_at_end(struct list *head, int data)
{
        struct list *newnode = NULL;
        newnode = make_new_node(data);

        struct list *temp=head;
        if(head==NULL)
                head= newnode;
        else
        {
                while(temp->next!= NULL)
                       temp=temp->next;
                temp->next = newnode;
        }
        return head;
}
//Function to insert node at the position given by user
struct list *insert_at_given_position(struct list *head, int data ,int position)
{
       int len= length(head);
			 //Invalid length position
       if((position < 0) || (position > len+1))
       {
             printf("invalid position\n");
             return head;
       }
       //head position
       else if(position==1)
             head= insert_at_head(head,data);
       //end position
       else if(position==len+1)
          head = insert_at_end(head,data);
       //In between Position
       else
       {
            struct list *newnode = NULL;
            newnode = make_new_node(data);
            struct list *before = head;
            for(int index = 0;index< position-2;index++)
                   before = before->next;
            struct list *after = before->next;

            before->next = newnode;
            newnode->next = after;

       }
       return head;

}
//displaying linked list
void print(struct list *head)
{
	//no data exists
	if(head==NULL)
		printf("no data to show\n");
	else
    {
      printf("head  ");
	  	struct list *temp=head;
      while(temp!=NULL)
	  	{
	     		printf("%d   ",temp->data);
	    		temp= temp->next;
	  	}
  	}
        printf("\n");
}

//deleting element at head position
struct list *delete_at_head(struct list *head)
{
        if(head== NULL)
            {
                printf("no data to delete\n");
                return head;
            }
        struct list *del_head = head;
        head= head->next;
        free(del_head);
        return head;

}
//deleting element at end position
struct list *delete_at_end(struct list *head)
{
        if(head == NULL)
            {
                printf("no data to delete\n");
                return head;
            }
        else if (head->next== NULL)
            {
                free(head);
                return NULL;
            }
        struct list *second_last = head;
        while(second_last->next->next!=NULL)
              second_last = second_last->next;

        //delete last node
        free(second_last->next);

        second_last->next= NULL;
        return head;

}
//deleting element at given position by user
struct list *delete_at_given_position(struct list *head, int position)
{
      int len = length(head);
       if((position < 0) || (position > len))
             printf("invalid position\n");
       //delete from head
       else if(position==1)
             head= delete_at_head(head);
       //delete from end
       else if(position==len)
             head = delete_at_end(head);
       //delete in between position element
       else
       {
           struct list *temp=head;
           for(int i=1;i<position-1;i++)
                temp =temp->next;
           struct list *pos_node = temp->next;
           temp->next = pos_node->next;
           free(pos_node);
       }
       return head;
}
//util function to print menu
void print_menu()
{
   printf("1.INSERT AT HEAD\n");
   printf("2.INSERT AT END\n");
   printf("3.INSERT AT GIVEN POSITION\n");
   printf("4.DELETE FROM HEAD\n");
   printf("5.DELETE FROM END\n");
   printf("6.DELETE FROM GIVEN POSITION\n");
   printf("7.PRINT THE LIST\n");
   printf("8.EXIT\n");
   printf("enter your choice :\n");

}
//main function
int main()
{
  printf("********************S T A R T***********************\n");
  int choice,data,position;
	struct list *head = NULL;
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
            head = insert_at_head(head,data);
            print(head);
            break;

       case 2:
             printf("enter data :\n");
             scanf("%d",&data);
             head = insert_at_end(head,data);
             print(head);
             break;

       case 3:
             printf("enter data :\n");
             scanf("%d",&data);
             printf("enter position :\n");
             scanf("%d",&position);
             head = insert_at_given_position(head,data,position);
             print(head);
             break;

       case 4:
               head=delete_at_head(head);
               print(head);
               break;
       case 5:
               head=delete_at_end(head);
               print(head);
               break;
       case 6:
               printf("enter position :\n");
               scanf("%d",&position);
               head= delete_at_given_position(head,position);
               print(head);
               break;
       case 7:
               print(head);
               break;
       case 8:
               exit(0);
       default:
                printf("wrong choice\n");
                break;
    }
  }

}
