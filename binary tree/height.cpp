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

int height_iterative(struct node *root)
{
	if(!root)
		return 0;
	struct node *temp;
	queue <struct node *> q;
	q.push(root);

	int level=0;

	while(q.empty()!=1)
	{
		int size = q.size();
		while(size--)
		{
				temp= q.front();
				q.pop();

				if(temp->left)
			 			q.push(temp->left);
				if(temp->right)
			 			q.push(temp->right);

	   }
		 level++;

	}
	return level;

}
int main(){
	struct node *root=NULL;
	root=newnode(1);
	root->left=newnode(2);
	root->right = newnode(3);
	root->left->left=newnode(4);
	cout<<height(root)<<endl<<height_iterative(root)<<endl;
}
