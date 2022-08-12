/*
Algorithm:
Use a path array path[] to store current root to leaf path.
Traverse from root to all leaves in top-down fashion. While traversing,
store data of all nodes in current path in array path[]. W
hen we reach a leaf node, print the path array.
*/

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

void print_array(int arr[],int len)
{
  for(int i=0;i<len;i++)
     cout<<arr[i]<<" ";
  cout<<endl;
}

void printPathRecursive(struct node *root,int path[],int length)
{
  if(!root)
    return;
  path[length++] = root->data;

  if (root->left == NULL && root->right == NULL)
      {
          print_array(path, length);
      }
      else
      {
          /* otherwise try both subtrees */
          printPathRecursive(root->left, path, length);
          printPathRecursive(root->right, path, length);
      }

}

void printPaths(struct node *root)
{
  int path[1000];
  printPathRecursive(root,path,0);
}

int main(){
	struct node *root=NULL;
	root=newnode(1);
	root->left=newnode(2);
	root->right = newnode(3);
	root->left->left=newnode(4);


	printPaths(root);
	cout<<endl;
}
