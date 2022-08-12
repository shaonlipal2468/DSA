#include<bits/stdc++.h>
using namespace std;
long long max_of_three(long long int n1,long long int n2,long long int n3)
  {
      return n1 > n2 ? (n1 > n3 ? n1 : n3) : (n2  >n3 ? n2 : n3);
  }

  long long min_of_three(long long int n1,long long int n2,long long int n3)
  {
      return  n1 < n2 ? (n1 < n3 ? n1 : n3) : (n2  <n3 ? n2 : n3);

  }


 // Function to find maximum product subarray
 long long maxProduct(int *arr, int n) {
     // code here
     long long int curr_max_prod,curr_min_prod;
     long long int prev_max_prod = arr[0];
     long long int prev_min_prod = arr[0];
     long long int ans = arr[0];

     for(int i=1;i<n;i++)
     {
         curr_max_prod = max_of_three(prev_max_prod*arr[i],
                                     prev_min_prod*arr[i],
                                     arr[i]);

        curr_min_prod = min_of_three(prev_max_prod*arr[i],
                                     prev_min_prod*arr[i],
                                     arr[i]);

        ans=max(ans,curr_max_prod);
        prev_max_prod=curr_max_prod;
        prev_min_prod=curr_min_prod;
     }

     return ans;

 }
  int main()
  {
     int arr[]={0,1,-5,7};
     int n=sizeof(arr)/sizeof(arr[0]);
     cout<<maxProduct(arr,n);
  }
