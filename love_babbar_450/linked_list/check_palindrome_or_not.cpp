//time complexity O(n) and space complexity is O(1)
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

//struct list *correct_head(struct list )

int check_palindrome(struct list *head)
{
  int flag=1;
  struct list *dummy_head = head;
  struct list *middle = middleNode(head);
  struct list *middle_ptr = reverse(middle);
  while(dummy_head && middle_ptr)
  {
     if(dummy_head->data!=middle_ptr->data)
        {
          flag=0;
          break;
        }
     dummy_head=dummy_head->next;
     middle_ptr=middle_ptr->next;
  }
  return flag;

}

int main()
{
   struct list* head=newnode(1);
   head->next = newnode(2);
   head->next->next = newnode(3);
   head->next->next->next = newnode(3);
   head->next->next->next->next = newnode(2);
   head->next->next->next->next->next = newnode(1);

   cout<<check_palindrome(head);




}
