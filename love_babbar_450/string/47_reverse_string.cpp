#include<bits/stdc++.h>
using namespace std;
void reverseString(char arr[],int size ) {

        int low=0;
        int high=size-1;

        while(low<=high)
        {
            swap(arr[low],arr[high]);
            low++;
            high--;
        }
    }
int main()
{
    char arr[]={'h','e','l','l','o'};
    int n=sizeof(arr)/sizeof(arr[0]);
   reverseString(arr,n);
   for(int i=0;i<n;i++)
      cout<<arr[i]<<" ";
   cout<<endl;
}
