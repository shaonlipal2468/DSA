//Time and Space complexity O(n)
#include <stdio.h>
#include<stdlib.h>

//binary search tree nodes
struct node{
	int data;
	struct node *left;
	struct node *right;
};

//creating one new node
struct node *newnode(int data)
{
	struct node *newn=(struct node *)malloc(sizeof(struct node));
	newn->left=NULL;
	newn->right=NULL;
	newn->data=data;
	return newn;
}
//Recursive version to insert element
struct node *insert(struct node *root,int data)
{
	if(root==NULL)
	   return newnode(data);
	else if (root->data>data)
	   root->left = insert(root->left,data);
 else if (root->data<data)
   root->right = insert(root->right,data);
 return root;
}


//Iterative version to insert data
struct node *insert_iterative(struct node *root,int data)
{
	struct node *current = root,*parent=NULL;
	if(root==NULL)
	   return newnode(data);
	while(current!=NULL)
	{
			parent = current;
			if(data<current->data)
					current= current->left;
			if(data>current->data)
					current= current->right;
	}

	if(data<parent->data)
	   parent->left= newnode(data);
	else
	   parent->right= newnode(data);
	return root;
}
//Inorder traversal
void inorder(struct node *root)
{
	if(!root)
	   return;
	inorder(root->left);
	printf("%3d",root->data);
	inorder(root->right);
}
//find min node value from root
struct node *find_min(struct node *root)
{
  if(root==NULL)
    return NULL;
  while(root->left!=NULL)
     root= root->left;
  return root;
}
//recursive version to delete node
struct node *deletion(struct node *root,int data_del)
{
  if(root==NULL)
     return NULL;
  else if(root->data>data_del)
     root->left = deletion(root->left,data_del);
  else if(root->data<data_del)
    root->right = deletion(root->right,data_del);

  else{ //we have found the node

          //case 1 : no child exists
          if(!root->left && !root->right)
              {
                  root=NULL;
                  return root;
              }

          //case 2 : only one child exists
          if(!root->right && root->left) //only left child exists
              {
                  struct node *temp = root;
                  root=root->left;
                  free(temp);
                  return root;
              }

          if(!root->left && root->right) //only right child exists
              {
                  struct node *temp = root;
                  root=root->right;
                  free(temp);
                  return root;
              }
          //case 3: both child exists
          if(root->left && root->right)
          {
                  struct node *temp;
                  temp = find_min(root->right); //finding the min successor of right sub tree
                  root->data = temp->data; //replacing by successor data
                  root->right = deletion(root->right,temp->data); //deleting the right successor node
                  return root;
          }

  }
  return root;
}

int main()
{
	struct node *root=NULL;
	root= insert_iterative(root,1);
	root= insert_iterative(root,2);
	root= insert_iterative(root,3);
	root= insert_iterative(root,4);
	inorder(root);



  //checking : deletion of leaf node
	root=NULL;
  root=newnode(3);
  root->left= newnode(2);
  root->left->left = newnode(1);
  root->right = newnode(4);

  inorder(root);
  printf("\n");
  deletion(root,4);
  inorder(root);
  printf("\n");

  //checking: deletion of a node having only one child
  struct node *root2=NULL;
  root2=newnode(6);
  root2->right=newnode(8);
  root2->left=newnode(2);
  root2->left->left=newnode(1);
  root2->left->right=newnode(4);
  root2->left->right->left=newnode(3);

  inorder(root2);
  printf("\n");
  deletion(root2,4);
  inorder(root2);
  printf("\n");

  //checking: deletion of a node having two children
  struct node *root3=NULL;
  root3=newnode(4);
  root3->right=newnode(8);
  root3->left=newnode(2);
  root3->right->left=newnode(5);
  root3->right->right=newnode(9);
  root3->right->left->right=newnode(7);
  root3->right->left->right->left=newnode(6);

  inorder(root3);
  printf("\n");
  deletion(root3,8);
  inorder(root3);
  printf("\n");
}
