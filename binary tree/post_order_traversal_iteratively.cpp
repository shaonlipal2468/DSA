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

void postorder_iteratively(struct node *root)
{
  // create an empty stack and push the root node
   stack<struct node*> s;
   s.push(root);

   // create another stack to store postorder traversal
   stack<int> out;

   // loop till stack is empty
   while (!s.empty())
   {
       // pop a node from the stack and push the data into the output stack
       struct node* curr = s.top();
       s.pop();

       out.push(curr->data);

       // push the left and right child of the popped node into the stack
       if (curr->left) {
           s.push(curr->left);
       }

       if (curr->right) {
           s.push(curr->right);
       }
   }

   // print postorder traversal
   while (!out.empty())
   {
       cout << out.top() << " ";
       out.pop();
   }
}
int main(){
   	struct node *root = newnode(1);
    root->left        = newnode(2);
    root->right       = newnode(3);
    root->left->left  = newnode(4);
    root->left->right = newnode(5);

	postorder_iteratively(root);
	cout<<endl;
}
