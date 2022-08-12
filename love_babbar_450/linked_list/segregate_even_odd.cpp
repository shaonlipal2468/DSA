#include<iostream>
#include<stdlib.h>
#include<queue>
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
struct list *insert_at_end(struct list *head, int data)
{
        struct list *newn = NULL;
        newn = newnode(data);

        struct list *temp=head;
        if(head==NULL)
                head= newn;
        else
        {
                while(temp->next!= NULL)
                       temp=temp->next;
                temp->next = newn;
        }
        return head;

}
struct list *segregate_even_odd(struct list *head)
{

  queue<int> even;
  queue<int> odd;

  struct list *temp=head;
  while(temp!=NULL)
  {
     if(temp->data % 2==0)
        even.push(temp->data);
    else
        odd.push(temp->data);
    temp=temp->next;
  }

  struct list *ans =NULL;
  while(even.size()>0)
  {
      ans=insert_at_end(ans,even.front());
      even.pop();
  }
  while(odd.size()>0)
  {
      ans=insert_at_end(ans,odd.front());
      odd.pop();
  }
  return ans;

}

int main()
{
   struct list* head=newnode(17);
   head->next = newnode(15);
   head->next->next = newnode(8);
   head->next->next->next = newnode(9);
   head->next->next->next->next =newnode(2);
   head->next->next->next->next->next =newnode(4);
   head->next->next->next->next->next->next =newnode(6);
   head = segregate_even_odd(head);
   print(head);
}
