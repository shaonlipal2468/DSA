//Delete nodes having greater value on right
#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

struct list{
  int data;
  struct list *next;
};
struct list *newnode(int data)
{
  struct list *newn = NULL;
  newn=(struct list *)malloc(sizeof(struct list));
  newn->data = data;
  newn->next=NULL;
  return newn;
}

int print(struct list *head)
{
  int count =0;
	if(head==NULL)
	   return count;

	else{

    cout<<"head  ";
		struct list *temp=head;
    while(temp!=NULL)
		{
      count++;
			cout<<temp->data<<" ";
			temp= temp->next;
		}
	}
        cout<<endl;
        return count;
}
struct list *insert_at_end(struct list *head, int data)
{
        struct list *newn = NULL;
        newn = newnode(data);

        struct list *temp=head;
        if(head==NULL)
                head= newn;
        else
        {
                while(temp->next!= NULL)
                       temp=temp->next;
                temp->next = newn;
        }
        return head;
}

struct list *util(struct list *head)
{
  struct list *curr=head,*next;
  struct list *ans=NULL;

  while(curr->next!=NULL)
  {
      next = curr->next;
      if(curr->data >=next->data)
             ans= insert_at_end(ans,curr->data);
      curr=curr->next;
  }
  ans= insert_at_end(ans,curr->data);
  return ans;
}
struct list *delete_node_having_greater_value_at_right(struct list *head)
{
  int length_old,length_new;
  head = util(head);
  length_old=print(head);

   while(1)
   {
     head = util(head);
     length_new=print(head);
     if(length_new==length_old)
         break;
      else
         length_old=length_new;
   }
  return head;

}


int main()
{
  /*
  struct list* head=newnode(12);
  head->next = newnode(15);
  head->next->next = newnode(10);
  head->next->next->next = newnode(11);
  head->next->next->next->next =newnode(5);
  head->next->next->next->next->next =newnode(6);
  head->next->next->next->next->next->next =newnode(2);
  head->next->next->next->next->next->next->next =newnode(3);*/

  vector<int> v={32, 433, 636, 121, 831, 102, 695, 509, 104, 776, 905, 876,
            219, 202, 326, 393, 141, 752, 504, 109, 640, 765, 537, 759,
            971, 857, 147, 716, 897, 484, 60, 928, 268, 47, 48, 98, 500,
            94, 607, 603, 221, 863, 831, 439, 416, 156, 183, 556, 259, 686,
            16, 250, 450, 552, 9, 772, 409, 155, 487, 305, 990, 898, 232, 258,
            945, 631, 707, 444, 724, 313, 47, 296, 527, 229, 734, 942, 736, 268,
            849, 995, 953, 865, 244, 754, 416, 604, 526, 176, 110, 364, 832, 100, 262};

//ans : 995 953 865 832 262(given)
  struct list* head=NULL;
  for(int i=0;i<v.size();i++)
      head= insert_at_end(head,v[i]);

  head = delete_node_having_greater_value_at_right(head);
}
