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

int path_sum_exists(struct node *root,int sum)
{
	if(root==NULL)
	{
		if(sum==0)
		   return 1;
		return 0;
	}
if(root->data==sum && !root->left && !root->right)
	   return 1;
else return (path_sum_exists(root->left,sum- root->data) ||
 						 path_sum_exists(root->right,sum- root->data));
}

int main(){
	struct node *root=NULL;
	root=newnode(1);
	root->left=newnode(2);
	root->right = newnode(3);
	root->left->left=newnode(4);
	cout<<path_sum_exists(root,8);
	cout<<endl;
}
