#include<iostream>
using namespace std;


struct node{
  int data;
  struct node *next;
};

struct node *make_newnode(int data)
{
  struct node *newnode =NULL;
  newnode = (struct node *)malloc(sizeof(struct node));
  newnode->next = NULL;
  newnode->data = data;
  return newnode;
}

void print(struct node *head)
{
    if(head==NULL)
      {
        cout<<"No data "<<endl;
        return;
      }
    struct node *temp=head;
    while(temp!=NULL)
    {
      cout<<temp->data<<"  ";
      temp=temp->next;
    }
    cout<<endl;
}

void deleteNode(struct node *del)
    {
       struct node *curr=del,*prev=del;
       while(curr->next)
       {
           prev=curr;
           curr->data = curr->next->data;
           curr=curr->next;
       }
       prev->next=NULL;
    }


int main()
{
  struct node *head=NULL;
  head = make_newnode(1);
  head->next = make_newnode(2);
  // head->next->next= make_newnode(3);
  // head->next->next->next = make_newnode(4);
  // head->next->next->next->next = make_newnode(5);


  cout<<"Before Deletion "<<endl;
  print(head);
  deleteNode(head);//->next->next->next);
  cout<<"After Deletion"<<endl;
  print(head);

}
