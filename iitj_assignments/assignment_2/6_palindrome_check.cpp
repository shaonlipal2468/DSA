#include <bits/stdc++.h>
#include"declarations.cpp"
using namespace std;

struct node{
	int data;
	struct node *next;
};

struct node *make_newnode(int data)
{
        struct node *newnode = NULL;
	      newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->next=NULL;
        return newnode;
}

struct node *insert_at_head(struct node *head, int data)
{
  struct node *newnode = NULL;
  newnode = make_newnode(data);

	if(head == NULL)
		head = newnode;
	else
	{
		newnode->next = head;
		head = newnode;
	}
	return head;
}

int length(struct node *head)
{
        int length= 0;
        if(head==NULL)
              return length;
        else
        {
             struct node *temp = head;
             while(temp!=NULL)
                  {
                       length+=1;
                       temp=temp->next;
                  }
             return length;
        }
}

 bool isPalindrome(struct node* head) {
        struct node* temp=head;
        Stack<int> s;
        int len = length(head);
        for(int i=1;i<=len/2;i++)
            {
                s.push(temp->data);
                temp=temp->next;

            }

        if(len%2!=0)
            temp=temp->next;

            while(temp!=NULL)
            {
                if(s.pop() != temp->data)
                    return false;

                temp=temp->next;
            }
        return true;

    }

int main()
{
   struct node *head =NULL;
	 head = insert_at_head(head,1);
	 head = insert_at_head(head,2);
	 head = insert_at_head(head,2);
	 head = insert_at_head(head,1);
   if(isPalindrome(head))
	    cout<<"Palindrome"<<endl;
	 else
	    cout<<"Not Palindrome"<<endl;
   return 0;
}
