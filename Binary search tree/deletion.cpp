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

struct node *find_min(struct node *root)
{
  if(root==NULL)
    return NULL;
  while(root->left!=NULL)
     root= root->left;
  return root;
}
//recursive version
struct node *deletion(struct node *root,int data_del)
{
  if(root==NULL)
     return NULL;
  else if(root->data>data_del)
     root->left = deletion(root->left,data_del);
  else if(root->data<data_del)
    root->right = deletion(root->right,data_del);

  else{ //we have found the node

          //case 1 : no child exists
          if(!root->left && !root->right)
              {
                  root=NULL;
                  return root;
              }

          //case 2 : only one child exists
          if(!root->right && root->left) //only left child exists
              {
                  struct node *temp = root;
                  root=root->left;
                  delete(temp);
                  return root;
              }

          if(!root->left && root->right) //only right child exists
              {
                  struct node *temp = root;
                  root=root->right;
                  delete(temp);
                  return root;
              }
          //case 3: both child exists
          if(root->left && root->right)
          {
                  struct node *temp;
                  temp = find_min(root->right); //finding the min successor of right sub tree
                  root->data = temp->data; //replacing by successor data
                  root->right = deletion(root->right,temp->data); //deleting the right successor node
                  return root;
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


int main()
{
  //checking : deletion of leaf node
	struct node *root=NULL;
  root=newnode(3);
  root->left= newnode(2);
  root->left->left = newnode(1);
  root->right = newnode(4);

  inorder(root);
  cout<<endl;
  deletion(root,4);
  inorder(root);
  cout<<endl;

  //checking: deletion of a node having only one child
  struct node *root2=NULL;
  root2=newnode(6);
  root2->right=newnode(8);
  root2->left=newnode(2);
  root2->left->left=newnode(1);
  root2->left->right=newnode(4);
  root2->left->right->left=newnode(3);

  inorder(root2);
  cout<<endl;
  deletion(root2,4);
  inorder(root2);
  cout<<endl;

  //checking: deletion of a node having two children
  struct node *root3=NULL;
  root3=newnode(4);
  root3->right=newnode(8);
  root3->left=newnode(2);
  root3->right->left=newnode(5);
  root3->right->right=newnode(9);
  root3->right->left->right=newnode(7);
  root3->right->left->right->left=newnode(6);

  inorder(root3);
  cout<<endl;
  deletion(root3,8);
  inorder(root3);
  cout<<endl;

}
