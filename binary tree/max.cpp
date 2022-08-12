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
//iterative
int max(struct node *root)
{
  int max_e= INT_MIN;
  struct node *temp;
  queue <struct node *>q;
  q.push(root);

  while(q.size()!=0)
  {
    temp = q.front();
    q.pop();

    if(temp->data> max_e)
       max_e = temp->data;
    if(temp->left)
      q.push(temp->left);]
    if(temp->right)
      q.push(temp->right);

  }
  return max_e;

}

//recursive
int max_func(struct node *root)
{
  int root_val,left_val,right_val,max=INT_MIN;
  if(root)
  {
    root_val= root->data;
    left_val = max_func(root->left);
    right_val = max_func(root->right);

    if(left_val>right_val)
       max = left_val;
    else max = right_val;

    if(root_val>max)
       max= root_val;

  }
  return max;
}


int main(){

	struct node *root=NULL;
	root=newnode(1);
	root->left=newnode(2);
	root->right = newnode(3);
	root->left->left=newnode(4);

	cout<<max(root);
	cout<<endl;
}
