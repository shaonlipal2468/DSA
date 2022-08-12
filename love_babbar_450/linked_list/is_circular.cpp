#include<iostream>
#include<stdlib.h>
using namespace std;
struct list {
  int data;
  struct list *next;
};
bool isCircular(struct list *head)
{
   // Your code here
   if(head==NULL ||head->next==NULL)
     return false;
    else if(head->next ==head)
      return true;
    struct list *temp=head;

    temp=temp->next;
    while(temp != head && temp != NULL)  //and not or
        temp=temp->next;
    if(temp==head)
      return true;
    else
      return false;
}
struct list *newnode(int data)
{
  struct list *newn = NULL;
  newn=(struct list *)malloc(sizeof(struct list));
  newn->data = data;
  newn->next=NULL;
  return newn;
}
int main()
{
   struct list* head=newnode(1);
   head->next = newnode(2);
   head->next->next = newnode(3);
   head->next->next->next = newnode(4);
   head->next->next->next->next =head;
   cout<<endl<<isCircular(head);

}
