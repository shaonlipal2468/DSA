#include<bits/stdc++.h>
using namespace std;
//Time complexity O(n)
//kadane's algorithm
int maxSubarraySum(int arr[], int n){
        int index[2],starting_index;
        int cursum=0,maxsum=INT_MIN;
        for(int i=0;i<n;i++)
        {
            cursum+=arr[i];
            if(cursum>maxsum)
               {
                 maxsum= cursum;
                 index[0]=starting_index; //save old start index
                 index[1]=i;  //end index
               }
            if(cursum<0)
            {
              starting_index=i+1;
              cursum = 0;
            }
        }
        cout<<index[0]<< " "<<index[1]<<endl;
        return maxsum;
    }
int main()
{
   //int arr[]={1,-2,3,2,-6,4};
   int arr[]={-3,-2,-1};
   int n=sizeof(arr)/sizeof(arr[0]);
   cout<<maxSubarraySum(arr,n);
}
