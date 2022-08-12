#include<bits/stdc++.h>
using namespace std;
//brute force
//Time complexity : O(n^3)
int maxSubarraySum_brute_force(int arr[], int n){
int maxsum=INT_MIN,currsum;
int index[2];
for(int i=0;i<n;i++)
{
    for(int j=i;j<n;j++)
      {
        currsum=0;
        for(int k=i;k<=j;k++)
            currsum+=arr[k];
        if(currsum>maxsum)
           {
             maxsum= currsum;
             index[0]=i;  //start index
             index[1]=j;  //end index
           }
      }
  }
cout<<index[0]<< " "<<index[1]<<endl;
return maxsum;

}
int main()
{
   int arr[]={1,-2,3,2,-6,4};
   int n=sizeof(arr)/sizeof(arr[0]);
   cout<<maxSubarraySum_brute_force(arr,n);
}
