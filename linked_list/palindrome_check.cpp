#include <bits/stdc++.h>

using namespace std;

struct node{
	int val;
	struct node *next;
};

struct node *newnodeutil(int data)
{
        struct node *newnode = NULL;
	      newnode = (struct node *)malloc(sizeof(struct node));
        newnode->val = data;
        newnode->next=NULL;
        return newnode;
}

struct node *insert_at_head(struct node *head, int data)
{
  struct node *newnode = NULL;
  newnode = newnodeutil(data);

	if(head == NULL)
	{
		head = newnode;
	}
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
        stack <int> s;
        int len = length(head);
				cout<<len<<endl;

            for(int i=1;i<=len/2;i++)
            {
                s.push(temp->val);
                temp=temp->next;

            }

        if(len%2!=0)
            temp=temp->next;

            while(temp!=NULL)
            {
                if(s.top() != temp->val)
                    return false;
								s.pop();
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
   cout<<isPalindrome(head);
   return 0;
}
