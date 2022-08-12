#include<iostream>
#include<stdlib.h>
using namespace std;

struct list{
	int data;
	struct list *prev;
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


int nth_node_from_end(struct list *head,int n)
{
   struct list *first=head,*second=head;
   int i;
   for(i=0;i<n;i++)
   {
       if(second)
          second=second->next;
       else
          break;
   }
    if(i<n)
       return -1;
    else if(i==n && second==NULL)
      return first->data;

    else
    {
      while(second->next!=NULL)
      {
          first=first->next;
          second=second->next;
      }
      return first->next->data;
    }


}
int main()
{
   struct list* head=NULL;
   head=newnode(23);
   head->next = newnode(89);
   head->next->next = newnode(50);
   head->next->next->next = newnode(30);
   head->next->next->next->next = newnode(72);

   int k=5;
   cout<<nth_node_from_end(head,k);
}
//23 89 50 30 72
