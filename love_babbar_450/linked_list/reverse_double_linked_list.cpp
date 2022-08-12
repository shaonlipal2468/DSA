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

struct list *newnode(int data)
{
        struct list *newn = NULL;
	      newn = (struct list *)malloc(sizeof(struct list));
        newn->data = data;
        newn->next=NULL;
        newn->prev=NULL;
        return newn;
}
struct list *insert_at_head(struct list *head,int data)
{
        struct list *newn = NULL;
        newn = newnode(data);

	if(head == NULL)
	{
		head = newn;
	}
	else
	{
		newn->next = head;
    head->prev = newn;
		head = newn;
	}
	return head;
}

struct list *reverse(struct list *head)
{
   struct list *temp=NULL,*curr=head;

//swap curr->prev and curr->next
   while(curr!=NULL)
   {
     temp=curr->prev;
     curr->prev=curr->next;
     curr->next= temp;
     curr=curr->prev;
   }

   if(temp != NULL )
        head = temp->prev;
   return head;

}

int main()
{
    struct list *head=NULL;
    head = insert_at_head(head,3);
    head = insert_at_head(head,2);
    head = insert_at_head(head,1);
    print(head);

    head = reverse(head);
    print(head);

}
