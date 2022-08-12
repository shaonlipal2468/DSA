//Greedy
#include<bits/stdc++.h>
using namespace std;
int solve(int arr[],int n)
{
  int min_pos=0,max_pos=0;
  for(int i=0;i<n;i++)
  {
     if(arr[min_pos]>arr[i])
        min_pos = i;
     if(arr[max_pos]<arr[i])
           max_pos = i;
  }

  int ans1 = min_pos+1+n-max_pos;
  int ans2 = max_pos+1+n-min_pos;
  int ans3 = max(min_pos,max_pos)+1;
  int ans4 = n-min(min_pos,max_pos);

  return min(min(min(ans1,ans2),ans3),ans4);
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
