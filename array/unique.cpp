#include<bits/stdc++.h>
using namespace std;
vector<int> unique(int arr[], int n)
{
  // Sorting the given array
  sort(arr, arr + n);
  vector<int> a;
  // Finding unique numbers
  for (int i=0; i<n; i++)
    {
    if(arr[i]==arr[i+1])
      continue;
    else
       a.push_back(arr[i]);
    }
    return a;
}
 void display(vector<int> arr)
 {
   //int n=sizeof(arr)/sizeof(arr[0]);
   for(int i=0;i<arr.size();i++)
      cout<<arr[i]<<" ";
   cout<<endl;
 }
 int main()
 {
   int arr[]={1,1,2,2,3,3};
   int n=6;
   vector<int> a = unique(arr,6);
   display(a);

 }
