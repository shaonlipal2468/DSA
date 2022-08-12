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
int height(struct node *root,int &flag)
{
    if(!root)
      return 0;
    int left=height(root->left,flag);
    int right=height(root->right,flag);
    if(abs(left-right)>1)
       flag= false;
    return max(left,right)+1;

}
//Function to check whether a binary tree is balanced or not.
bool isBalanced(struct node *root)
{
    //  Your Code here
    int flag= 1;
    height(root,flag);
    return flag;
}

int main(){
	struct node *root=NULL;
	root=newnode(1);
	root->left=newnode(2);
	root->right = newnode(3);
	root->left->left=newnode(4);
	cout<<isBalanced(root)<<endl;
}
