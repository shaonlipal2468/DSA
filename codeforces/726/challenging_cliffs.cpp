#include<bits/stdc++.h>
using namespace std;

void print_array(int arr[],int n)
{
  for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
  cout<<endl;

}
void solve(int arr[],int n)
{
   sort(arr,arr+n);
   if(n<=2)
   {
     print_array(arr,n);
     return;
   }


   int index=0;
   int diff=INT_MAX;
   for(int i=1;i<n;i++)
     {
       if((abs(arr[i]-arr[i-1])) <diff)
       {
         index=i-1;
         diff = abs(arr[i]-arr[i-1]);
       }

     }
     //cout<<index<<endl;
   for(int i=index+1;i<n;i++)
     cout<<arr[i]<<" ";
   for(int i=0;i<=index;i++)
     cout<<arr[i]<<" ";
   cout<<endl;
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
      solve(arr,n);
  }
}
