//whether merge point exists in the given linked list or not
#include<iostream>
#include<stdlib.h>
using namespace std;

struct list{
	int data;
	struct list *next;
};
struct list *newnodeutil(int data)
{
        struct list *newnode = NULL;
	      newnode = (struct list *)malloc(sizeof(struct list));
        newnode->data = data;
        newnode->next=NULL;
        return newnode;
}
int length(struct list *head)
{
        int length= 0;
        if(head==NULL)
              return length;
        else
        {
             struct list *temp = head;
             while(temp!=NULL)
                  {
                       length+=1;
                       temp=temp->next;
                  }
             return length;
        }
}

struct list *merge_point(struct list *list1, struct list *list2)
{
  int l1=0,l2=0,diff=0;
  struct list *head1,*head2;

  l1= length(list1);
  l2= length(list2);

//head1 will always point to the larger list
  if (l1>l2)
  {
    head1 = list1;
    head2 = list2;
    diff = l1-l2;
  }

  else{
    head1 = list2;
    head2 = list1;
    diff = l2-l1;
  }

  for(int i=0;i<diff;i++)
        head1 = head1->next;
  while(head1 && head2)
   {
      if(head1==head2)
           return head1;  //merge point found
      head1= head1->next;
      head2= head2->next;
   }
  return NULL; //no merge point found


}

int main() {

  struct list *list1= newnodeutil(1);
  list1->next = newnodeutil(2);
  list1->next->next = newnodeutil(3);
  list1->next->next->next = newnodeutil(6);
  list1->next->next->next->next = newnodeutil(7);

  struct list *list2= newnodeutil(4);
  list2->next = newnodeutil(5);
  list2->next->next = list1->next->next->next;


  struct list *ans =merge_point(list1,list2);
      cout<<ans->data;


  return 0;
}
