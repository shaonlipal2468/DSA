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


void display(struct list *head)
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

struct list *reverse(struct list *head)
{
  struct list * current,*prev,*next;
  current=head;
  prev=NULL;
  next=NULL;

  while(current!=NULL)
  {
     next= current->next;
     current->next= prev;
     prev= current;
     current=next;
  }
  head = prev;
  return head;
}

struct list*reverse_in_group(struct list *head,int k)
{
  if(head==NULL)
      return NULL;
  struct list * current,*prev,*next;
  current=head;
  prev=NULL;
  next=NULL;

  int count =0;

  while(current!=NULL && count<k)
  {
    next=current->next;
    current->next = prev;
    prev=current;
    current=next;
    count++;
  }

  /* next is now a pointer to (k+1)th node
    Recursively call for the list starting from current.
    And make rest of the list as next of first node */

  if(next!=NULL)
    head->next = reverse_in_group(next,k);


  return prev;
}


int main()
{
  struct list *head=newnodeutil(1);
  head->next=newnodeutil(2);
  head->next->next=newnodeutil(3);
  head->next->next->next=newnodeutil(4);
  head->next->next->next->next=newnodeutil(5);
  head->next->next->next->next->next=newnodeutil(6);


  display(head);
  head=reverse(head);
  display(head);

  head=reverse_in_group(head,4);
  display(head);

}
