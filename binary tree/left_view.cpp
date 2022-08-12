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
vector<int> leftView(struct node *root)
{
   // Your code here
   vector<int> ans;
   if(!root)
		return ans;
   queue<struct node *> q;
   struct node *temp;
   q.push(root);
   while(!q.empty())
   {
       int size=q.size();
      for(int i=0;i<size;i++)
       {
           temp= q.front();
		       q.pop();
           if(i==0)
               ans.push_back(temp->data);

           if(temp->left)
				       q.push(temp->left);
			     if(temp->right)
				       q.push(temp->right);
       }
   }
   return ans;
}
int main(){
	struct node *root=NULL;
	root=newnode(1);
	root->left=newnode(2);
	root->right = newnode(3);
	root->left->left=newnode(4);

	vector<int> ans = leftView(root);
	for(int i=0;i<ans.size();i++)
	   cout<<ans[i]<<" ";
	cout<<endl;
}
