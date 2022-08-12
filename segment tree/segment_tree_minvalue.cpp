#include<bits/stdc++.h>
using namespace std;

int getMid(int a,int b)
{
  return a+(b-a)/2;
}


int constructUtil(int arr[],int ss,int se,int *st,int si)
{
  if(ss==se)
     st[si]=arr[ss];
  else
  {
    int mid = getMid(ss,se);
    int left = constructUtil(arr, ss, mid, st, si*2+1);
    int right = constructUtil(arr, mid+1, se, st, si*2+2);
    st[si] = min(left,right);
  }
  return st[si];
}

int *construct_tree(int arr[],int n)
{
  int  x = (int)(ceil(log2(n)));
  int max_size = (int)pow(2,x+1)-1;
  int *st = new int[max_size];
  constructUtil(arr,0,n-1,st,0);
  return st;
}
int getMinUtil(int *st,int ss,int se,int qs,int qe,int si)
{
  //completely inside
  if(qs<=ss && qe>=se )
    return st[si];

  //completely outside
  if(qs>se || ss>qe)
    return INT_MAX;

  //partially overlapped
  int mid = getMid(ss,se);
  int left = getMinUtil(st,ss,mid,qs,qe,2*si+1);
  int right = getMinUtil(st,mid+1,se,qs,qe,2*si+2);
  return min(left,right);

}

int getMin(int *st,int n,int qs,int qe)
{
   if(qs<0 || qe>n-1|| qs>qe)
   {
     cout<<"invalid"<<endl;
     return -1;
   }
   return getMinUtil(st,0,n-1,qs,qe,0);
}

int main()
{
  int arr[]={1,5,2,-3,4,-1};
  int n = sizeof(arr)/sizeof(arr[0]);
  int *st = construct_tree(arr, n);
  cout<<"Min of values in given range = "<<getMin(st, n, 0, 4)<<endl;

}
