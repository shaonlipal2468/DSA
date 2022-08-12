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

bool printAncestor(struct node *root,int data)
{
  if(!root)
    return false;
  if (root->data==data)
    return true;
  if(printAncestor(root->left,data) || printAncestor(root->right,data))
     {
       cout<<root->data<<" ";
       return true;
    }
    return false;
}

int main()
{

  /* Construct the following binary tree
              1
            /   \
          2      3
        /  \
      4     5
     /
    7
  */
  struct node *root = newnode(1);
  root->left        = newnode(2);
  root->right       = newnode(3);
  root->left->left  = newnode(4);
  root->left->right = newnode(5);
  root->left->left->left  = newnode(7);

  printAncestor(root, 7);


  return 0;
}
