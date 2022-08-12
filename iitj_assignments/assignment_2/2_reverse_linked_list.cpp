#include<iostream>
#include"declarations.cpp"
using namespace std;
//linked list node
struct node
{
  int data;
  struct node * next;
};
//make new node
struct node *make_newnode(int data)
{
  struct node *newnode = NULL;
  newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = data;
  newnode->next=NULL;
  return newnode;
}
//printing the linked list
void print(struct node *head)
{
  if(!head)
  {
    cout<<"no data"<<endl;
    return;
  }
  struct node *temp= head;
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp= temp->next;
  }
  cout<<endl;
}

//reversal using stack
struct node *reverse(struct node *head)
{
    Stack<struct node *> s;
    struct node *temp=head;
    while(temp->next!=NULL)
    {
        s.push(temp);
        temp=temp->next;
    }
    head=temp;
    while(s.isEmpty()!=true)
    {
        temp->next = s.pop();
        temp=temp->next;
    }
    temp->next=NULL;
    return head;

}
int main()
{
  struct node *head=NULL;
  head = make_newnode(1);
  head->next = make_newnode(2);
  head->next->next = make_newnode(3);
  head->next->next->next = make_newnode(4);

  print(head);
  head= reverse(head);
  print(head);

}
