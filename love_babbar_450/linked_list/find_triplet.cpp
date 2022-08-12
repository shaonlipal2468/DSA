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

int find_pair(struct list *first,struct list *end,int sum,int true_sum)
{
  int count =0;
	while(first && end && first!=end && end->next != first)
	{
		 if(first->data + end->data == sum)
		 {
			  count++;
			  cout<<true_sum-(first->data+end->data)<<" "<<first->data <<" "<<end->data<<endl;
				first= first->next;
				end= end->prev;
		 }
		 else if(first->data + end->data < sum)
		    first=first->next;
			else
			   end=end->prev;
	}
  return count;
}

int find_triplet(struct list *head,int sum)
{
	  struct list *first,*current,*last=head;
    int count =0;
    while(last->next!=NULL)
        last=last->next;

    for(current = head;current!=NULL;current=current->next)
    {
      first = current->next;
      count +=find_pair(first,last,sum-current->data,sum);
    }

    return count;
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
		int sum=17;
    print(head);
		cout<<find_triplet(head,sum)<<endl;
}
