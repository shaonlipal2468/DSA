#include<bits/stdc++.h>
using namespace std;

int *merge_arr(int *a,int *b,int *c,int n,int m)
{
  //int c[m+n];
  int i=0,j=0,k=0;
  while(i<n && j<m)
  {

    if(a[i] <=b[j])
       c[k++]= a[i++];
    else
       c[k++]=b[j++];
  }

  if(j>=m)
  {
    for(int p=i;p<n;p++)
       c[k++]= a[p];
  }

  if(i>=n)
  {
    for(int p=j;p<m;p++)
       c[k++]= b[p];
  }
 return c;
}

int main()
{
  int a[]={1,2,2,4,6};
  int b[]={1,2,3,4,8,9};
  int n=sizeof(a)/sizeof(a[0]),m=sizeof(b)/sizeof(b[0]);
  int c[m+n];
  int *ptr=merge_arr(a,b,c,5,6);
  for(int p=0;p<m+n;p++)
    cout<<ptr[p]<<" ";
  cout<<endl;
}
