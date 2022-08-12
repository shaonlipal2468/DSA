#include <iostream>

using namespace std;

bool triplet(int arr[],int n,int sum)
{
    int i,j,k;
    for(i=0;i<n-2;i++)
    {
        for(j=i+1;j<n-1;j++)
        {
            for(k=j+1;k<n;k++)
            {
                if(arr[i]+arr[j]+arr[k]==sum)
                   {
                       cout<<arr[i]<<arr[j]<<arr[k]<<endl;
                       return true;
                   }
            }
        }
    }
    return false;
}

int main()
{
  int arr[]={3,2,7,5,1,9,11};
  int n=sizeof(arr)/sizeof(arr[0]);
  int sum=20;
  cout<<triplet(arr,n,sum);
   
   return 0;
}
