#include<iostream>
#include<stdlib.h>
using namespace std;

struct list{
	int data;
	struct list *prev;
  struct list *next;
};

void print(struct list *head)
{
	if(head==NULL)
		cout<<"no data to show"<<endl;
	else{

    cout<<"head ";
		struct list *temp=head;
    while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp= temp->next;
		}
	}
        cout<<endl;
}
struct list *newnodeutil(int data)
{
        struct list *newnode = NULL;
	      newnode = (struct list *)malloc(sizeof(struct list));
        newnode->data = data;
        newnode->next=NULL;
        newnode->prev=NULL;
        return newnode;
}

struct list *insert_at_head(struct list *head,int data)
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
    head->prev = newnode;
		head = newnode;
	}
	return head;
}
struct list* rotate(struct list *head,int k)
{
  struct list *curr=head,*prev,*temp;
  for(int i=0;i<k;i++)
      {
        prev=curr;
        curr=curr->next;
      }
  prev->next = NULL;
  curr->prev=NULL;
  temp=curr;

  while(curr->next!=NULL)
    curr=curr->next;

  curr->next=head;
  head->prev=curr;

  head= temp;
  return head;
}

int main()
{
   struct list *head=NULL;
   head = insert_at_head(head,5);
   head = insert_at_head(head,4);
   head = insert_at_head(head,3);
   head = insert_at_head(head,2);
   head = insert_at_head(head,1);

   print(head);

   int k=2;
   head = rotate(head,k);
   print(head);
}
