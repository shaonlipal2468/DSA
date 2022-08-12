//print sum of each levels and max sum level
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

int max_sum_level(struct node *root)
{
  int max_sum=0,sum;
  if(!root)
		return 0;
	struct node *temp;
	queue <struct node *> q;
	q.push(root);

	while(q.empty()!=1)
	{
    sum=0;
		int size = q.size();
		while(size--)
		{
				temp= q.front();
				q.pop();
        sum+=temp->data;

				if(temp->left)
			 			q.push(temp->left);
				if(temp->right)
			 			q.push(temp->right);

	   }
     if(max_sum< sum)
        max_sum=sum;
      cout<<sum<< " ";
	}
	return max_sum;
}

int main(){
	struct node *root=NULL;
	root=newnode(1);
	root->left=newnode(2);
	root->right = newnode(3);
	root->left->left=newnode(4);
	int max_sum = max_sum_level(root);
  cout<<endl<<"max sum is "<<max_sum<<endl;
}
