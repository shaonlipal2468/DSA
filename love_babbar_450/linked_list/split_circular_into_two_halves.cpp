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
void print(struct list *head)
{
  //cout<<"hi"<<endl;
  struct list *temp=head;
	if(head==NULL)
		cout<<"no data to show"<<endl;
  else{
    cout<<"Head ";
    do{
       cout<<temp->data<<" ";
       temp=temp->next;
      }while(temp!=head);
     cout<<endl;
    }
}
void splitList(struct list *head, struct list **head1_ref,struct list **head2_ref)
{
    // your code goes here
    struct list * fast=head,*slow=head;
    while(fast->next !=head && fast->next->next!=head)
    {
        fast=fast->next->next;
        slow=slow->next;
    }

    if(fast->next->next==head) //even numbers
          fast->next->next = slow->next;
    else//odd numbers
          fast->next=slow->next;
          
    *head2_ref=slow->next;
    slow->next=head;
    *head1_ref=head;
}

int main()
{
   struct list* head=NULL;
   head = newnode(1);
   head->next = newnode(2);
   head->next->next = newnode(3);
   head->next->next->next = newnode(4);
   head->next->next->next->next =head;
   print(head);
   struct list *head1_ref=NULL,*head2_ref=NULL;
   splitList(head,&head1_ref,&head2_ref);
   print(head1_ref);
   print(head2_ref);
}
