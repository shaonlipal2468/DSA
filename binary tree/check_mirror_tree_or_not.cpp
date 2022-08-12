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

int check_mirror_tree(struct node *root1,struct node *root2)
{
  if(!root1 && !root2)
     return 1;
  if(!root1 || !root2)
     return 0;
  else  return ((root1->data == root2->data) &&
                check_mirror_tree(root1->left,root2->right) &&
                check_mirror_tree(root1->right,root2->left));
}

int main(){
	struct node *root=NULL;
	root=newnode(1);
	root->left=newnode(2);
	root->right = newnode(3);
	root->left->left=newnode(4);

  struct node *root2=NULL;
	root2=newnode(1);
	root2->left=newnode(3);
	root2->right = newnode(2);
	root2->right->right=newnode(4);


	if(check_mirror_tree(root,root2))
	   cout<<"They are mirror tree"<<endl;
	else
	  cout<<"They are not mirror tree"<<endl;

	cout<<endl;
}
