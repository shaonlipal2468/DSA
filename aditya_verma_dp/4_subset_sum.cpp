#include<bits/stdc++.h>
using namespace std;
bool isSubsetSum(int arr[],int n,int sum)
{
  if(sum==0)
     return true;
  if(n==0)
     return false;
  else if(arr[n-1]>sum)
     return isSubsetSum(arr,n-1,sum);
  else return isSubsetSum(arr,n-1,sum-arr[n-1]) ||
              isSubsetSum(arr,n-1,sum);
}

bool subset_sum_bottom_up(int arr[],int n,int sum)
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
      else t[i][j]= t[i-1][j] || t[i-1][j-arr[i-1]];
    }
  }
  return t[n][sum];
}

int main()
{
 int arr[] = { 3, 34, 4, 12, 5, 2 };
 int sum = 9;
 int n = sizeof(arr) / sizeof(arr[0]);
 if (isSubsetSum(arr, n, sum) == true)
     printf("Found a subset with given sum");
 else
     printf("No subset with given sum");
 return 0;
}
