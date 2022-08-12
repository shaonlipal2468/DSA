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
vector<int> top_view(struct node *root)
{
    //Your code here
    unordered_map<int,vector<int>> m;
    m[0].push_back(root->data);
    int hd = 0;
    queue<pair<struct node *,int>> q;
    q.push(make_pair(root,hd));
    while(!q.empty())
    {
        auto temp = q.front();
        q.pop();

        int new_hd = temp.second;
        struct node * temp_node = temp.first;

        if(temp_node->left)
            {
              m[new_hd-1].push_back(temp_node->left->data);
              q.push(make_pair(temp_node->left,new_hd-1));
            }

        if(temp_node->right)
           {
             m[new_hd+1].push_back(temp_node->right->data);
             q.push(make_pair(temp_node->right,new_hd+1));
           }

    }
    vector<int> ans;
    auto it_min = min_element(m.begin(),m.end());
    auto it_max = max_element(m.begin(),m.end());


    for(int i=it_min->first;i<=it_max->first;i++)
       {
         auto it = m.find(i);
         ans.push_back(it->second[0]);
       }
   return ans;
}

int main(){
	struct node *root=NULL;
  root = newnode(1);
  root->left = newnode(2);
  root->right = newnode(3);
  root->left->left = newnode(4);
  root->left->right = newnode(5);
  root->right->left = newnode(6);
  root->right->right = newnode(7);
  root->right->left->right = newnode(8);
  root->right->right->right = newnode(9);

	vector<int> ans = top_view(root);
	for(int i=0;i<ans.size();i++)
	   cout<<ans[i]<<" ";
	cout<<endl;
}
