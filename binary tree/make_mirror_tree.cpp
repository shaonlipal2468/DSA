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

struct node * make_mirror_tree(struct node *root)
{
  struct node *temp;
 if(root)
 {
   make_mirror_tree(root->left);
   make_mirror_tree(root->right);
   temp=root->left;
   root->left= root->right;
   root->right= temp;
 }
 return root;
}

void inorder(struct node *root)
{
	if(!root)
	   return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main(){
	struct node *root=NULL;
	root=newnode(1);
	root->left=newnode(2);
	root->right = newnode(3);
	root->left->left=newnode(4);

	root = make_mirror_tree(root);
  inorder(root);
	cout<<endl;
}
