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

void print(struct list *head)
{
	if(head==NULL)
		cout<<"no data to show"<<endl;
	else{

		struct list *temp=head;
                while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp= temp->next;
		}
	}
        cout<<endl;
}

struct list *find_middle(struct list *head)
{
  struct list *slow,*fast;
  slow=head;
  fast=head;
  if(head==NULL)
     cout<<"no data"<<endl;


  while(fast->next!=NULL && fast->next->next!=NULL)
   {
       fast = fast->next->next;
       slow = slow->next;
   }
 return slow;
}

int main()
{

	struct list *head = NULL;

	head = insert_at_head(head,6);
  head = insert_at_head(head,7);
	head = insert_at_head(head,8);
	head = insert_at_head(head,9);
	head = insert_at_head(head,10);

  print(head);
  cout<<find_middle(head)->data<<endl;
}
