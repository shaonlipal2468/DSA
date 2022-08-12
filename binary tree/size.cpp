
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
//recursive
int size_tree(struct node *root)
{
  if(root==NULL)
    return 0;
  else return size_tree(root->left)+1+size_tree(root->right);
}
//iterative
int size_recursive(struct node *root)
{
  int size=0;
  if(!root)
    return 0;
  struct node *temp;
  queue <struct node *> q;
  q.push(root);

  while(q.size()!=0)
  {
    temp= q.front();
    q.pop();
    size++;

    if(temp->left)
       q.push(temp->left);
    if(temp->right)
       q.push(temp->right);
  }

  return size;
}


int main(){
	struct node *root=NULL;
	root=newnode(1);
	root->left=newnode(2);
	root->right = newnode(3);
	root->left->left=newnode(4);

	cout<<size_tree(root)<<endl<<size_recursive(root)<<endl;
	cout<<endl;
}
