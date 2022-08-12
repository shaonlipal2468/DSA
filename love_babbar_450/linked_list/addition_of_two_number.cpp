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
struct list *insert_at_head(struct list *head, int data)
{
  struct list *newn = NULL;
  newn = newnode(data);

	if(head == NULL)
		head = newn;
	else
	{
		newn->next = head;
		head = newn;
	}
	return head;
}
struct list *add_zeros(struct list *head,int length,int diff)
{
   struct list *temp=head;
   while(temp->next!=NULL)
      temp=temp->next;

   for(int i=0;i<diff;i++)
   {
      temp->next = newnode(0);
      temp=temp->next;
   }
   return head;
}
struct list *add(struct list *head1,struct list *head2,int n,int m)
{
    if(m==0)
       return head1;
    else if(n==0)
        return head2;
    head1=reverse(head1);
    head2= reverse(head2);
    struct list *big,*small;

    if(n>m)
    {
       int diff = n-m;
       head2 = add_zeros(head2,m,diff);
       big = head1;
       small=head2;
    }
    else
    {
      int diff = m-n;
      head1 = add_zeros(head1,n,diff);
      big=head2;
      small=head1;
    }
    int loop;
    if(n>=m)
      loop=n;
    else
      loop=m;


    struct list *ans=NULL;
    int carry = 0;
    for(int i=0;i<loop;i++)
    {
      int add = big->data+small->data+carry;
      ans= insert_at_head(ans,add%10);
      carry = add/10;
      big= big->next;
      small=small->next;
    }
    while(carry)
    {
      ans = insert_at_head(ans,carry%10);
      carry=carry/10;
    }
    return ans;

}

int main()
{
  struct list* head1=newnode(3);
  head1->next = newnode(4);
  head1->next->next = newnode(5);

  int n=3;

  struct list* head2=newnode(4);
  head2->next = newnode(5);
  int m=2;

  struct list *addition = add(head2,head1,m,n);
  print(addition);

}
