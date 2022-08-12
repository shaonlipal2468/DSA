//Time and Space complexity O(n)
#include <bits/stdc++.h>
#include"declarations.cpp"
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
//level order traversal
void bfs_traversal(struct node *root)
{
  if(!root)
    return;
  struct node *temp;
	Queue<struct node *> q;
  q.enQueue(root);

  while(q.size_()!=0)
  {
    temp= q.deQueue();
    if(temp->left)
       q.enQueue(temp->left);
    if(temp->right)
       q.enQueue(temp->right);
    cout<<temp->data<<" ";

  }
}

//pre order using recursion
void preorder(struct node *root)
{
	if(root==NULL)
	  return;
  cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

//inorder using recursion
void inorder(struct node *root)
{
	if(root==NULL)
	  return;

	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
//postorder using recursion
void postorder(struct node *root)
{
	if(root==NULL)
	  return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}
//pre order using stack
void preorder_using_stack(struct node *root)
{
  if(!root)
    return;
  struct node *temp;
  stack <struct node *> s;
  s.push(root);
  while(s.size()!=0)
  {
    temp= s.top();
    s.pop();
   cout<<temp->data<<" ";
    if(temp->right)
       s.push(temp->right);
    if(temp->left)
       s.push(temp->left);
  }
}
//main function
int main()
{
	struct node *root=NULL;
  root=newnode(8);
	root->left = newnode(3);
	root->right = newnode(10);

	root->left->left = newnode(1);
	root->left->right = newnode(6);
	root->left->right->left=newnode(4);
	root->left->right->right=newnode(7);

	root->right->right= newnode(14);
	root->right->right->left = newnode(13);

  cout<<"bfs_traversal "<<endl;
	bfs_traversal(root);
	cout<<endl;

  cout<<"Inorder using recursion"<<endl;
	inorder(root);
	cout<<endl;

	cout<<"Preorder using recursion"<<endl;
	preorder(root);
	cout<<endl;

	cout<<"Postorder using recursion"<<endl;
	postorder(root);
	cout<<endl;


  cout<<"Preorder using stack"<<endl;
	preorder_using_stack(root);
	cout<<endl;

}
