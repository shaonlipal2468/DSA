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

void find_pair(struct list *head,int sum)
{
	 struct list * first=head,* end=head;
	 while(end->next!=NULL)
	    end= end->next;
	bool found=false;
	while(first!=end && end->next != first)
	{
		 if(first->data + end->data == sum)
		 {
			 found= true;
			  cout<<first->data <<" "<<end->data <<endl;
				first= first->next;
				end= end->prev;
		 }
		 else if(first->data + end->data < sum)
		    first=first->next;
			else
			   end=end->prev;
	}
	if(found==false)
	  cout<<"no pair"<<endl;
}
int main()
{
    struct list *head=NULL;
		head = insert_at_head(head,9);
		head = insert_at_head(head,8);
		head = insert_at_head(head,6);
		head = insert_at_head(head,5);
    head = insert_at_head(head,4);
    head = insert_at_head(head,2);
    head = insert_at_head(head,1);
		int sum=7;
    print(head);
		find_pair(head,sum);
}
