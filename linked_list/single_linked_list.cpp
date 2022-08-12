#include<iostream>
#include<stdlib.h>
using namespace std;

struct list{
	int data;
	struct list *next;
};

struct list *newnodeutil(int data)
{
        struct list *newnode = NULL;
	      newnode = (struct list *)malloc(sizeof(struct list));
        newnode->data = data;
        newnode->next=NULL;
        return newnode;
}

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
struct list *insert_at_head(struct list *head, int data)
{
  struct list *newnode = NULL;
  newnode = newnodeutil(data);

	if(head == NULL)
	{
		head = newnode;
	}
	else
	{
		newnode->next = head;
		head = newnode;
	}
	return head;
}

struct list *insert_at_end(struct list *head, int data)
{
        struct list *newnode = NULL;
        newnode = newnodeutil(data);

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
struct list *insert_at_given_position(struct list *head, int data ,int position)
{
       int len= length(head);
       if((position < 0) || (position > len))
       {
             cout<<"invalid position"<<endl;
             return head;
       }

       else if(position==1)
       {
             head= insert_at_head(head,data);
       }
       else if(position==len+1)
       {
             head = insert_at_end(head,data);
       }

       else
       {
            struct list *newnode = NULL;
            newnode = newnodeutil(data);
            struct list *before = head;
            for(int index = 0;index< position-2;index++)
                   before = before->next;
            struct list *after = before->next;

            before->next = newnode;
            newnode->next = after;

       }
       return head;

}

void print(struct list *head)
{
	if(head==NULL)
		cout<<"no data to show"<<endl;
	else{
    cout<<"head  ";
		struct list *temp=head;
    while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp= temp->next;
		}
	}
        cout<<endl;
}

struct list *delete_at_head(struct list *head)
{
        if(head== NULL)
            {
                cout<<"no data to delete"<<endl;
                return head;
            }
        struct list *del_head = head;
        head= head->next;
        free(del_head);
        return head;

}

struct list *delete_at_end(struct list *head)
{
        if(head == NULL)
            {
                cout<<"no data to delete"<<endl;
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

struct list *delete_at_given_position(struct list *head, int position)
{
      int len = length(head);
       if((position < 0) || (position > len))
       {
             cout<<"invalid position"<<endl;

       }

       else if(position==1)
       {
             head= delete_at_head(head);
       }
       else if(position==len)
       {
             head = delete_at_end(head);
       }

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

int main()
{

	struct list *head = NULL;
	head = insert_at_head(head,6);
  head = insert_at_head(head,7);
	head = insert_at_head(head,8);
	head = insert_at_head(head,9);
	head = insert_at_head(head,10);
  head = insert_at_end(head,11);
  head = insert_at_given_position(head,12,4);
  print(head);
  head=delete_at_head(head);
  print(head);

  head=delete_at_end(head);
  print(head);

  head= delete_at_given_position(head,2);
  print(head);
}
