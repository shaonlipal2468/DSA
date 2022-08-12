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
int getMin(int *st,int ss,int se,int qs,int qe,int si)
{
  //completely inside
  if(qs<=ss && qe>=se )
    return st[si];

  //completely outside
  if(qs>se || ss>qe)
    return INT_MAX;

  //partially overlapped
  int mid = getMid(ss,se);
  int left = getMin(st,ss,mid,qs,qe,2*si+1);
  int right = getMin(st,mid+1,se,qs,qe,2*si+2);
  return min(left,right);

}


int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
     cin>>arr[i];
  int *st = construct_tree(arr, n);

  int q,qs,qe;
  cin>>q;
  while(q--)
  {
    cin>>qs>>qe;
    cout<<getMin(st,0,n-1,qs,qe,0)<<endl;
  }
}
