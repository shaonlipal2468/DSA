#include<bits/stdc++.h>
using namespace std;

struct node{
  int data;
  struct node *next;
};

struct node *newnode(int data)
{
  struct node *newn=NULL;
  newn=(struct node *)malloc(sizeof(struct node));
  newn->data = data;
  newn->next = NULL;
  return newn;
}

struct node * insert(struct node *head,int item)
{
  struct node *newn=newnode(item);
    newn->next=head;
    head=newn;
  return head;
}

struct node * pop(struct node *head)
{
  if(head==NULL)
     return head;
  int data = head->data;
  cout<<"popped element is : "<<data<<endl;
  struct node *temp=head;
  head=head->next;
  free(temp);
  return head;
}

void display(struct node *head)
{
  if(head==NULL)
  {
    cout<<"no data"<<endl;
    return;
  }
  struct node *temp=head;
  while(temp)
    {
      cout<<temp->data<<" ";
      temp=temp->next;
    }
    cout<<endl;
}


int main()
{
  struct node *head=NULL;

  head=insert(head,2);
  display(head);
  head=insert(head,3);
  display(head);
  head=insert(head,4);
  display(head);
  head=pop(head);
  head=pop(head);head=pop(head);head=pop(head);head=pop(head);
  display(head);

}
