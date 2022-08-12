#include<iostream>
using namespace std;

//linked list node structure
struct node{
  int data;
  struct node *next;
};
//make new node
struct node *make_newnode(int data)
{
  struct node *newnode =NULL;
  newnode = (struct node *)malloc(sizeof(struct node));
  newnode->next = NULL;
  newnode->data = data;
  return newnode;
}
//print the list
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

//using recursion

struct node * merege_two_sorted_linked_list(struct node* head1, struct node* head2)
{
    //if first list is empty return second
    if (head1==NULL)
        return head2;
    //if second list is empty return first
    if (head2==NULL)
        return head1;
    if (head1->data < head2->data)
    {
        head1->next = merege_two_sorted_linked_list(head1->next, head2);
        return head1;
    }
    else
    {
        head2->next = merege_two_sorted_linked_list(head1, head2->next);
        return head2;
    }
}


int main()
{
  struct node *head1=NULL;
  head1 = make_newnode(1);
  head1->next = make_newnode(3);
  head1->next->next= make_newnode(5);
  head1->next->next->next = make_newnode(7);


  struct node *head2=NULL;
  head2 = make_newnode(2);
  head2->next = make_newnode(4);
  head2->next->next= make_newnode(6);
  head2->next->next->next = make_newnode(8);
  head2->next->next->next->next = make_newnode(10);

  merege_two_sorted_linked_list(head1,head2);
  cout<<"After Merging"<<endl;
  print(head1);

}
