#include<iostream>
#include<stdlib.h>
using namespace std;

struct list {
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
struct list*reverse(struct list *head)
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

struct list* add_1_to_linked_list(struct list *head)
{
   if(!head)
     return newnode(1);

   int carry=0;
   struct list* curr=head,*prev=head;
   int add=curr->data+1;
   curr->data = add%10;
   carry=add/10;

   curr=curr->next;

   while(curr && carry)
   {
      add= curr->data + carry;
      curr->data = add%10;
      carry=add/10;
      prev=curr;
      curr=curr->next;
   }
   while(carry)
   {
      prev->next= newnode(carry%10);
      carry = carry/10;
   }
   return head;
}

int main()
{
   struct list* head=newnode(9);
   head->next = newnode(9);
   head->next->next = newnode(9);

   print(head);

   head=reverse(head);
   print(head);

   head= add_1_to_linked_list(head);
   print(head);
   head=reverse(head);
   print(head);
}
