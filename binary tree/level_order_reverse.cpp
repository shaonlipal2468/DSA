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

vector<int> level_order_reverse(struct node *root)
{
    	vector<int> ans;
      if(!root)
         return ans;

	    queue<struct node *> q;
	    q.push(root);
	    struct node *temp;

	    while(!q.empty())
	    {
	        temp=q.front();
	        q.pop();
	        ans.push_back(temp->data);

	       if(temp->right)
	             q.push(temp->right);
	       if(temp->left)
	             q.push(temp->left);

	    }
	    reverse(ans.begin(),ans.end());   //this vector acting like a stack
	    return ans;
}

int main(){
	struct node *root=NULL;
	root=newnode(1);
	root->left=newnode(2);
	root->right = newnode(3);
	root->left->left=newnode(4);

	vector<int> ans = level_order_reverse(root);
	for(int i=0;i<ans.size();i++)
	   cout<<ans[i]<<" ";
	cout<<endl;
}
