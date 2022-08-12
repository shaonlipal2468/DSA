//Each traversal recursive manner
//Time complexity O(n) and space complexity O(n)

#include<iostream>
#include<stdlib.h>
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

void inorder(struct node *root)
{
	if(!root)
	   return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void preorder(struct node *root)
{
	if(!root)
	   return;
  cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(struct node *root)
{
	if(!root)
	   return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

int main(){
	struct node *root=NULL;
	root=newnode(1);
	root->left=newnode(2);
	root->right = newnode(3);
	root->left->left=newnode(4);

	inorder(root);
	cout<<endl;

	preorder(root);
	cout<<endl;

	postorder(root);
	cout<<endl;
  return 0;
}
