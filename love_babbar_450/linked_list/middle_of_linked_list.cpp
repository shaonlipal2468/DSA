//Leetcode 876
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
struct list * middleNode(struct list * head) {
    struct list * fast=head,*slow=head;
    while(fast->next !=NULL && fast->next->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    if(fast->next)
        return slow->next;
    else
        return slow;
}

int main()
{
   struct list* head=newnode(1);
   head->next = newnode(2);
   head->next->next = newnode(3);
   head->next->next->next = newnode(4);
   head->next->next->next->next = newnode(5);
   //head->next->next->next->next->next = newnode(6);

   struct list * middle = middleNode(head);
   print(middle);


}
