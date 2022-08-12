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
bool search(struct node *root,int data)
{
  if(!root)
    return false;
  if(root->data== data)
    return true;
  bool res_left= search(root->left,data);
  if(res_left)
     return true;
  bool res2= search(root->right,data);
  return res2;
}

struct node * search_iterative(struct node *root,int data)
{
  if(!root)
   return NULL;
  struct node *temp;
  queue <struct node *> q;
  q.push(root);

  while(q.size()!=0)
  {
      temp = q.front();
      q.pop();
      if(temp->data == data)
         return temp;
      if(temp->left)
         q.push(temp->left);
      if(temp->right)
        q.push(temp->right);

  }
  return NULL;  //not found
}

struct node *lca(struct node *root,struct node *alpha,struct node *beta)
{
  if(root==NULL)
    return NULL;

   if (root->data == alpha->data || root->data == beta->data)
       return root;

   // Look for keys in left and right subtrees
   struct node *left_lca  = lca(root->left, alpha, beta);
   struct node *right_lca = lca(root->right, alpha, beta);

   // If both of the above calls return Non-NULL, then one key
   // is present in once subtree and other is present in other,
   // So this node is the LCA
   if (left_lca && right_lca)  return root;

   // Otherwise check if left subtree or right subtree is LCA
   return (left_lca != NULL)? left_lca: right_lca;
}

int main()
{
  struct node *root = newnode(1);
  root->left        = newnode(2);
  root->right       = newnode(3);
  root->left->left  = newnode(4);
  root->left->right = newnode(5);
  root->left->left->left  = newnode(7);
  cout<<lca(root,search_iterative(root,2),search_iterative(root,3))->data;
}
