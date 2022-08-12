//iterative manner
//Time complexity O(n) and space complexity O(n)
#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *newnode(int data)
{
	struct node *newn=(struct node *)malloc(sizeof(struct node));
	newn->left=NULL;
	newn->right=NULL;
	newn->data=data;
	return newn;
}
//
// void inorder_using_stack(struct node *root)
// {
//  stack <struct node *> s;
//  struct node *curr;
//  while(1)
//  {
//    while(root)
//    {
//      s.push(root);
//      root=root->left;
//    }
//    if(s.size()==0)
//       break;
//     curr=s.top();
//     s.pop();
//    cout<<curr->data<<" ";
//    root=root->right;
//  }
// }
void inorder_using_stack(struct node *root)
{
	stack <struct node *> s;
	struct node *curr=root;
	 // if the current node is null and the stack is also empty, we are done
	while(!s.empty() || curr!=NULL)
	{
	  	// if the current node exists, push it into the stack (defer it)
        // and move to its left child
		  if(curr)
			{
				  s.push(curr);
					curr=curr->left;
			}
			// otherwise, if the current node is null, pop an element from the stack,
      // print it, and finally set the current node to its right child
			else
			{
				 curr = s.top();
				 s.pop();
				 cout<<curr->data<<" ";
				 curr=curr->right;
			}
	}
}

int main(){
	// struct node *root=NULL;
	// root=newnode(1);
	// root->left=newnode(2);
	// root->right = newnode(3);
	// root->left->left=newnode(4);


   	struct node *root = newnode(1);
    root->left        = newnode(2);
    root->right       = newnode(3);
    root->left->left  = newnode(4);
    root->left->right = newnode(5);

	inorder_using_stack(root);
	cout<<endl;
}
