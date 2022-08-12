//iterative manner
//Time complexity O(n) and space complexity O(n)


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

void level_order_traversal(struct node *root)
{
  if(!root)
    return;
  struct node *temp;
  queue <struct node *> q;
  q.push(root);

  while(q.size()!=0)
  {
    temp= q.front();
    q.pop();

    if(temp->left)
       q.push(temp->left);
    if(temp->right)
       q.push(temp->right);

    cout<<temp->data<<" ";

  }
}

int main(){
	struct node *root=NULL;
	root=newnode(1);
	root->left=newnode(2);
	root->right = newnode(3);
	root->left->left=newnode(4);

	level_order_traversal(root);
	cout<<endl;
}
