#include<bits/stdc++.h>
using namespace std;

int getMid(int a,int b)
{
  return a+(b-a)/2;
}

void updateRangeUtil(int *st,int *lazy_tree,int si, int ss, int se, int us,
                     int ue, int diff)
{
    if (lazy_tree[si] != 0)  //pending updates
    {
        st[si] += (se-ss+1)*lazy_tree[si];
        if (ss != se) //not leaf node
        {
            lazy_tree[si*2 + 1]   += lazy_tree[si];
            lazy_tree[si*2 + 2]   += lazy_tree[si];
        }
        lazy_tree[si] = 0;
    }

    // out of range
    if (ss>se || ss>ue || se<us)
        return ;
    // Current segment is fully in range
    if (ss>=us && se<=ue)
    {
        // Add the difference to current node
        st[si] += (se-ss+1)*diff;
        // same logic for checking leaf node or not
        if (ss != se)
        {
            lazy_tree[si*2 + 1]   += diff;
            lazy_tree[si*2 + 2]   += diff;
        }
        return;
    }
    // overlaps, recur for children,
    int mid = (ss+se)/2;
    updateRangeUtil(st,lazy_tree,si*2+1, ss, mid, us, ue, diff);
    updateRangeUtil(st,lazy_tree,si*2+2, mid+1, se, us, ue, diff);

    st[si] = st[si*2+1] + st[si*2+2];
}

/*  us and eu -> starting and ending indexes of update query
    ue  -> ending index of update query
    diff -> which we need to add in the range us to ue */
void updateRange(int *st,int *lazy_tree,int n, int us, int ue, int diff)
{
   updateRangeUtil(st,lazy_tree,0, 0, n-1, us, ue, diff);
}


int getSumUtil(int *st,int *lazy_tree,int ss,int se,int qs,int qe,int si)
{
  if (lazy_tree[si] != 0) //update remaining
    {
        st[si] += (se-ss+1)*lazy_tree[si];
        if (ss != se) //not lead node
        {
            lazy_tree[si*2+1] += lazy_tree[si];
            lazy_tree[si*2+2] += lazy_tree[si];
        }
        // unset the lazy value for current node as it has
        lazy_tree[si] = 0;
    }
    if (ss>se || ss>qe || se<qs) //completely outside
          return 0;

      // If this segment lies in range
      if (ss>=qs && se<=qe)
          return st[si];

      // segment overlaps with the given range
      int mid = (ss + se)/2;
      return getSumUtil(st,lazy_tree,ss, mid, qs, qe, 2*si+1) +
             getSumUtil(st,lazy_tree,mid+1, se, qs, qe, 2*si+2);
}

int getSum(int *st,int *lazy_tree,int n, int qs, int qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }
    return getSumUtil(st,lazy_tree,0, n-1, qs, qe, 0);
}

int construct_tree(int arr[],int ss,int se,int *st,int si)
{
  if(ss==se)
     st[si]=arr[ss];
  else
  {
    int mid = getMid(ss,se);
    int left = construct_tree(arr, ss, mid, st, si*2+1);
    int right = construct_tree(arr, mid+1, se, st, si*2+2);
    st[si] = (left+right);
  }
  return st[si];
}

int main()
{
  int arr[] = {1, 3, 5, 7, 9, 11};
   int n = sizeof(arr)/sizeof(arr[0]);

   int  x = (int)(ceil(log2(n)));
   int max_size = (int)pow(2,x+1)-1;
   int *st = new int[max_size];
   int *lazy_tree = new int[max_size];
   //lazy_tree initialization
   for(int i=0;i<max_size;i++)
      lazy_tree[i]=0;

   // Build segment tree from given array
   construct_tree(arr,0,n-1,st,0);

   cout<<"Sum of values in given range = "<< getSum(st,lazy_tree,n, 1, 3)<<endl;

   // Add 10 to all nodes at indexes from 1 to 5.
    updateRange(st,lazy_tree,n, 1, 5, 10);

    cout<<"Sum of values in given range = "<< getSum(st,lazy_tree,n, 1, 3)<<endl;

}
