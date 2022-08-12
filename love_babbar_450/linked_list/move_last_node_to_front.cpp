#include<iostream>
#include<stdlib.h>
using namespace std;

struct list{
	int data;
	struct list *next;
};

struct list *newnode(int data)
{
  struct list *newn = NULL;
  newn=(struct list *)malloc(sizeof(struct list));
  newn->data = data;
  newn->next=NULL;
  return newn;
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

struct list *move_last_node_to_front(struct list* head)
{
   if(!head || !head->next)
      return head;
   struct list *curr=head;
   while(curr->next->next)
       curr=curr->next;
   curr->next->next=head;
   head=curr->next;
   curr->next=NULL;

   return head;

}
int main()
{
  struct list *head=newnode(1);
  head->next = newnode(2);
  head->next->next=newnode(3);
  head->next->next->next=newnode(4);
  head->next->next->next->next=newnode(5);
  print(head);
  head = move_last_node_to_front(head);
  print(head);
}
