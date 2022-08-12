#include <bits/stdc++.h>

using namespace std;

bool triplet(int arr[],int n,int sum)
{
    int i,j,k;
    sort(arr,arr+n);
    for(i=0;i<n-2;i++)
    {
        
        int low=i+1;
        int high=n-1;
        while(low<high){
            if(arr[low]+arr[high]+arr[i]==sum)
            {
                cout<<arr[low]<<" " <<arr[high]<<" "<<arr[i]<<endl;
                return true;
            }
            
            else if (arr[low]+arr[high]+arr[i]<sum)
                low++;
            else
                high--;
        }
    }
    return false;
}

int main()
{
  int arr[]={2,2,2,2,1,9,11};
  int n=sizeof(arr)/sizeof(arr[0]);
  int sum=6;
  cout<<triplet(arr,n,sum);
   return 0;
}
