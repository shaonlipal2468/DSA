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


struct node * insert(struct node *root,int data)
{
  struct node *newn = newnode(data);
  struct node *temp;
  queue <struct node *> q;
  q.push(root);

  while(q.size()!=0)
  {
        temp = q.front();
        q.pop();

        if(temp->left)
            q.push(temp->left);
        else{
            temp->left = newn;
            break;
          }

        if(temp->right)
          q.push(temp->right);
        else{
          temp->right = newn;
          break;
        }


  }
return root;
}

void inorder(struct node *root)
{
	if(!root)
	   return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
int main(){
	struct node *root=NULL;
	root=newnode(1);
	root->left=newnode(2);
	root->right = newnode(3);
	root->left->left=newnode(4);

	root = insert(root,12);
  inorder(root);
	cout<<endl;
}
