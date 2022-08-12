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

struct list *intersection(struct list *head1,struct list *head2)
{
   struct list *temp1=head1,*temp2=head2;
   struct list *ans=NULL;
   while(temp1 && temp2)
   {
      if(temp1->data ==temp2->data)
         {
           ans = insert_at_end(ans,temp1->data);
           temp1= temp1->next;
           temp2=temp2->next;
         }
      else if (temp1->data <temp2->data )
          temp1=temp1->next;
      else
          temp2=temp2->next;
   }
   return ans;
}

int main()
{
  struct list *head1=newnode(1);
  head1->next=newnode(2);
  head1->next->next=newnode(3);
  head1->next->next->next=newnode(4);
  head1->next->next->next->next=newnode(6);


  struct list *head2=newnode(2);
  head2->next=newnode(3);
  head2->next->next=newnode(4);
  head2->next->next->next=newnode(6);

  struct list *ans =intersection(head1,head2);
  print(ans);

}
