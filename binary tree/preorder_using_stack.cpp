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
void preorder_using_stack(struct node *root)
{
  if(!root)
    return;
  struct node *temp;
  stack <struct node *> s;
  s.push(root);
  while(s.size()!=0)
  {
    temp= s.top();
    s.pop();
   cout<<temp->data<<" ";
    if(temp->right)
       s.push(temp->right);
    if(temp->left)
       s.push(temp->left);
  }
}
int main(){
	struct node *root=NULL;
	root=newnode(1);
	root->left=newnode(2);
	root->right = newnode(3);
	root->left->left=newnode(4);
	preorder_using_stack(root);
	cout<<endl;
}
