#include<bits/stdc++.h>
using namespace std;

int count_subset_sum(int arr[],int n,int sum)
{
  int t[n+1][sum+1];
  int i,j;
  for(i=0;i<=sum;i++)
     t[0][i] = false;

  for(i=0;i<=n;i++)
     t[i][0] = true;

  for(i=1;i<=n;i++)
  {
    for(j=1;j<=sum;j++)
    {
      if(arr[i-1]>j)
         t[i][j] = t[i-1][j];
      else t[i][j]= t[i-1][j] + t[i-1][j-arr[i-1]];
    }
  }
  return t[n][sum];
}
int count_subset_difference(int arr[],int n,int diff)
{
  int sum_arr=0,i;
  for(i=0;i<n;i++)
     sum_arr+=arr[i];
  int sum= (diff+sum_arr)/2;
  return count_subset_sum(arr,n,sum);
}

int main()
{
  int arr[]={1};
  int differnce = 2;
  int n=sizeof(arr)/sizeof(arr[0]);
  cout<<count_subset_difference(arr,n,differnce);

}
