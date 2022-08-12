#include<bits/stdc++.h>
using namespace std;
void print_arr(int arr[],int n)
{
  for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";
  cout<<endl;
}
void bubbleSort(int *arr, int n)
{
    bool swapped;
    // Your code here
    for(int i=0;i<n-1;i++)
    {
        swapped=false;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
              {
                  int temp=arr[j];
                  arr[j]=arr[j+1];
                  arr[j+1]=temp;
                  swapped =true;
              }
        }
        if(swapped==false)
          break;
    }
}



int main()
{
  int arr[]={6,2,1,9,19,3,20};
  int n = sizeof(arr)/sizeof(arr[0]);
  bubbleSort(arr,n);
  print_arr(arr,n);
}
