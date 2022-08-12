//Find loop exists in linked list or not;
//If loop exists return the first node of the loop
#include<iostream>
#include<stdlib.h>
using namespace std;

struct list{
	int data;
	struct list *next;
};
struct list *make_new_node(int data)
{
        struct list *newnode = NULL;
	      newnode = (struct list *)malloc(sizeof(struct list));
        newnode->data = data;
        newnode->next=NULL;
        return newnode;
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


struct list *find_begin_loop(struct list *head)
{
  int loop_exists=0;
  struct list *slow,*fast;
  slow=head;
  fast=head;
  //finding loop exists or not
  struct list *temp;
  while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL)
  {
    slow=slow->next;
    fast=fast->next->next;

    if(slow==fast)
    {
      loop_exists=1;
      break;
    }
  }
  //if loop exists then removal and return the first node of loop
  if(loop_exists)
  {
    slow = head;
    while (slow!=fast) {
       //storing the previous node of fast pointer
       // to get last node of the loop
      temp=fast;
      fast=fast->next;
      slow=slow->next;

    }
    //remove loop
    temp->next = NULL;
    return slow; //slow will give the fist node of loop
  }
  else return NULL;
}

int main()
{
  struct list* head = make_new_node(1);
  head->next = make_new_node(2);
  head->next->next = make_new_node(3);
  head->next->next->next = make_new_node(4);
  head->next->next->next->next = make_new_node(5);

  //Creating loop for testing
  head->next->next->next->next->next = head->next->next;
  struct list *answer = find_begin_loop(head);
  if(answer)
     cout<<"fist node of loop is "<<answer->data<<endl;
  cout<<"after removing loop ";
  print(head);

}
