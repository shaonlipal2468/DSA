
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

int indentical_structure(struct node *root1,struct node *root2)
{
  if(!root1 && !root2)
     return 1;
  if(!root1 || !root2)
     return 0;
  else  return ((root1->data == root2->data) &&
                indentical_structure(root1->left,root2->left) &&
                indentical_structure(root1->right,root2->right));

}

int indentical_structure_iterative(struct node *root1,struct node *root2)
{
  if(!root1 && !root2)
     return 1;
  if(!root1 || !root2)
     return 0;
  queue <struct node *> q1,q2;
  struct node *temp1,*temp2;

  q1.push(root1);
  q2.push(root2);

    while(q1.size()!=0 && q2.size()!=0 )
    {
        temp1= q1.front();
        q1.pop();

        temp2= q2.front();
        q2.pop();

        if(temp1->data != temp2->data)
           return 0;

        if(temp1->left && temp2->left)
         {
           q1.push(temp1->left);
           q2.push(temp2->left);
        }
         else if(temp1->left || temp2->left)
              return 0;

          if(temp1->right && temp2->right)
               {
                 q1.push(temp1->right);
                 q2.push(temp2->right);
              }
               else if(temp1->right || temp2->right)
                    return 0;

    }
   return 1;
}

int main(){
	struct node *root=NULL,*root_n=NULL;
	root=newnode(1);
	root->left=newnode(2);
	root->right = newnode(3);
	root->left->left=newnode(4);

  root_n=newnode(1);
  root_n->left=newnode(2);

	cout<<indentical_structure(root,root_n)<<endl<<indentical_structure_iterative(root,root_n);
	cout<<endl;
}
