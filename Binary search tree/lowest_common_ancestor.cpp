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

struct node *search(struct node *root,int data)
{
  if(root==NULL)
     return NULL;
  else if(root->data ==data )
    return root;
  else if(root->data>data)
    return search(root->left,data);
  else if(root->data<data)
    return search(root->right,data);

  return NULL; //not found

}
//recursive function
struct node *lca(struct node *root,struct node *alpha,struct node *beta)
{
    if(root==NULL)
      return NULL;
    else if (root->data >alpha->data &&  root->data >beta->data)
      return lca(root->left,alpha,beta);
    else if (root->data <alpha->data &&  root->data < beta->data)
      return lca(root->right,alpha,beta);
    return root;
}

//iterative function
struct node *lca_iterative(struct node *root,struct node *alpha,struct node *beta)
{
	while(1)
	{
		if(root==NULL)
		  return NULL;
		else if((root->data >alpha->data &&  root->data <beta->data)||
						(root->data <alpha->data &&  root->data >beta->data))
						return root;
		  else if (root->data >alpha->data &&  root->data >beta->data)
			    root= root->left;
			else if (root->data <alpha->data &&  root->data < beta->data)
			    root= root->right;
	}
	return NULL;
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

 struct node *alpha,*beta;
 alpha = search(root,2);
 beta = search(root,6);

 struct node *lca_node = lca(root,alpha,beta);
 cout<<lca_node->data<<endl;
 struct node *lca_node_iterative = lca(root,alpha,beta);
 cout<<lca_node_iterative->data<<endl;

}
