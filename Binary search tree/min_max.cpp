//TC O(n) and space complexity O(n)
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

int min(struct node *root)
{
  if(root==NULL)
    return -1;
  while(root->left!=NULL)
    root= root->left;
  return root->data;
}

int max(struct node *root)
{
  if(root==NULL)
    return -1;
  while(root->right!=NULL)
    root= root->right;
  return root->data;
}
int main()
{
	struct node *root=NULL;
	root= insert(root,3);
	root= insert(root,2);
	root= insert(root,5);
	root= insert(root,4);

  cout<<min(root)<<endl;
  cout<<max(root)<<endl;

}
