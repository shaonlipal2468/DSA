#include<bits/stdc++.h>
using namespace std;

int solve(int arr[],int n)
{
  int sum =0;
  for(int i=0;i<n;i++)
    sum+=arr[i];

  if(sum%n!=0)
     return -1;
  int count =0;
  int dist = sum/n;
  for(int i=0;i<n;i++)
   {
       if(arr[i]>dist)
         count++;
   }
   return count;
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
     int n;
     cin>>n;
     int arr[n];
     for(int i=0;i<n;i++)
       cin>>arr[i];
     cout<<solve(arr,n)<<endl;
  }
}
