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


struct node *min(struct node *root)
{
  if(root==NULL)
    return NULL;
  while(root->left!=NULL)
    root= root->left;
  return root;
}

struct node *max(struct node *root)
{
  if(root==NULL)
    return NULL;
  while(root->right!=NULL)
    root= root->right;
  return root;
}


//TC :O(n^2) and SC: O(n)
int isBST(struct node *root)
{
  if(root==NULL)
    return 1;
   if(root->left && max(root->left)->data > root->data)
      return 0;
   if(root->right && min(root->right)->data < root->data)
      return 0;
   if(!isBST(root->left) || !isBST(root->right))
      return 0;
  return 1;
}

int isBST_modified(struct node *root,int min,int max)
{
  if(root==NULL)
     return 1;
  return (root->data >min && root->data <max &&
          isBST_modified(root->left,min,root->data) &&
          isBST_modified(root->right,root->data,max));

}

int main()
{
  struct node *root=NULL;
  root=newnode(4);
  root->left = newnode(2);
  root->right = newnode(8);
  root->right->left = newnode(5);
  root->right->right = newnode(9);
  root->right->left->right = newnode(7);
  root->right->left->right->left = newnode(6);
  cout<<isBST(root);
  cout<<isBST_modified(root,INT_MIN,INT_MAX);

}
