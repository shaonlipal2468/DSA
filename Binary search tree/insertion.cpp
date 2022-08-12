//Time and Space complexity O(n)
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
//Recursive version
struct node *insert(struct node *root,int data)
{
	if(root==NULL)
	   return newnode(data);
	else if (root->data>data)
	   root->left = insert(root->left,data);
 else if (root->data<data)
   root->right = insert(root->right,data);
 return root;
}


//Iterative version
struct node *insert_iterative(struct node *root,int data)
{
	struct node *current = root,*parent=NULL;
	if(root==NULL)
	   return newnode(data);
	while(current!=NULL)
	{
			parent = current;
			if(data<current->data)
					current= current->left;
			if(data>current->data)
					current= current->right;
	}

	if(data<parent->data)
	   parent->left= newnode(data);
	else
	   parent->right= newnode(data);
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

int main()
{
	struct node *root=NULL;
	root= insert_iterative(root,1);
	root= insert_iterative(root,2);
	root= insert_iterative(root,3);
	root= insert_iterative(root,4);
	inorder(root);
}
