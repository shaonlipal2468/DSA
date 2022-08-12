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
int half_node_recursive(struct node *root)
{
  if(root==NULL)
     return 0;
  int count=0;
  if((root->left && !root->right)||(!root->left && root->right))
     count++;

  int left_count = half_node_recursive(root->left);
  int right_count = half_node_recursive(root->right);
  count= count+left_count+right_count;
  return count;
}


//iterative
int half_node(struct node *root)
{
  int half=0;
  if(!root)
    return 0;
  struct node *temp;
  queue <struct node *> q;
  q.push(root);

  while(q.size()!=0)
  {
    temp= q.front();
    q.pop();

    if((temp->left && !temp->right)||(!temp->left && temp->right))
      half++;

    if(temp->left)
       q.push(temp->left);
    if(temp->right)
       q.push(temp->right);

  }
  return half;
}

int main(){
	struct node *root=NULL;
	root=newnode(1);
	root->left=newnode(2);
	root->right = newnode(3);
	root->left->left=newnode(4);


	cout<<half_node(root)<<endl<<half_node_recursive(root);
	cout<<endl;
}