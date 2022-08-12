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
int main()
{
 int arr[] = { 2,3,5,6,8,10 };
 int sum = 10;
 int n = sizeof(arr) / sizeof(arr[0]);
 cout<<count_subset_sum(arr, n, sum)<<endl;
 return 0;
}
