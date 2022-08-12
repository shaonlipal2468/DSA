#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left,*right;
};

struct node *newnode(int data)
{
    struct node *newn = (struct node *)malloc(sizeof(struct node));
    newn->data = data;
    newn->left=NULL;
    newn->right=NULL;
    return newn;
}
void print_vector(vector<int> v)
{
    for(int i=0;i<v.size();i++)
       cout<<v[i]<<" ";
    cout<<endl;
}

void traversal(struct node *root)
{
    vector<int> inorder,preorder,postorder;

    stack<pair<struct node *,int>> s;
    s.push(make_pair(root,1));

    while(!s.empty())
    {
        int state = s.top().second;
        struct node *curr= s.top().first;
        if(state == 1)   //add to preorder, state++, try to go to left
        {
            preorder.push_back(curr->data);
            s.top().second++;

            if(curr->left)
                s.push(make_pair(curr->left,1));
        }

        else if(state == 2)//add to inorder, state++, try to go to right
        {
            inorder.push_back(curr->data);
            s.top().second++;

            if(curr->right)
                s.push(make_pair(curr->right,1));
        }
        else//(state == 3) add to postorder, pop from stack
        {
            postorder.push_back(curr->data);
            s.pop();
        }
    }

    print_vector(preorder);
    print_vector(inorder);
    print_vector(postorder);

}

int main()
{
  struct node *root=newnode(50);
  root->left = newnode(25);
  root->right = newnode(75);
  root->left->left = newnode(12);
  root->left->right= newnode(37);
  root->right->left = newnode(62);
  root->right->right = newnode(87);

  traversal(root);

}
