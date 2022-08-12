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

int height(struct node *root)
{
  if(root==NULL)
     return 0;
  int lheight= height(root->left);
  int rheight = height(root->right);

  return 1+max(lheight,rheight);
}

int diameter(struct node *root)
{
  if(root==NULL)
     return 0;

  int lheight = height(root->left);
  int rheight = height(root->right);

  int ldiameter = diameter(root->left);
  int rdiameter = diameter(root->right);

  return max(1+lheight+rheight,max(ldiameter,rdiameter));
}


int main(){
	struct node *root=NULL;
	root=newnode(1);
	root->left=newnode(2);
	root->right = newnode(3);
	root->left->left=newnode(4);

	cout<<diameter(root);
	cout<<endl;
}
