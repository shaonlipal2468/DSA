#include<bits/stdc++.h>
using namespace std;
//Time complexity is O(nlogn)
int max_of_three(int n1,int n2,int n3)
{
  return n1>n2?(n1>n3?n1:n3):(n2>n3?n2:n3);
}
int maxcrossing_sum(int arr[],int low,int mid,int high)
{
   //sum of left half of the mid
   int sum=0,left_sum=INT_MIN;
   for (int i = mid; i >= low; i--)
   {
      sum+=arr[i];
      left_sum=max(left_sum,sum);
   }

   //sum of right half of the mid
   int right_sum=INT_MIN;
   sum=0;
   for(int i=mid+1;i<=high;i++)
   {
      sum+=arr[i];
      right_sum=max(right_sum,sum);
   }
   return max_of_three(left_sum,right_sum,left_sum+right_sum);
}
int maxSubarraySum(int arr[],int low,int high)
{
  if(low==high)
       return arr[low];
  int mid= (low+high)/2;
  return max_of_three(maxSubarraySum(arr,low,mid),
                      maxSubarraySum(arr,mid+1,high),
                      maxcrossing_sum(arr,low,mid,high));
}
int main()
{
   int arr[]={1,-2,3,2,-6,4};
   int n=sizeof(arr)/sizeof(arr[0]);
   cout<<maxSubarraySum(arr,0,n-1);
}
