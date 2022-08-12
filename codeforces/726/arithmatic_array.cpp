#include<bits/stdc++.h>
using namespace std;

int solve(int arr[],int n)
{
   int sum=0;
   for(int i=0;i<n;i++)
     sum+=arr[i];
   if(sum==n)
     return 0;
   else if(n+1-sum >=0)
     return 1;
   else
     {
       int x = n+1-sum;
       return abs(x)+1;
     }
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
