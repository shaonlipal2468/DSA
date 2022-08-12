#include<bits/stdc++.h>
using namespace std;
void print_arr(int arr[],int n)
{
  for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";
  cout<<endl;
}
int select(int arr[], int i,int n)
{
    int min_idx= i;
    for (int j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;
    return min_idx;
}
void selectionSort(int arr[], int n)
{
  //code here
  int i,j;
  for(i=0;i<n-1;i++)
  {
      int min_index =i;
      //select returns the min index after i
      min_index = select(arr,i,n);
      //if arr[i] is the minimum one don't swap
      if(min_index!=i)
      {
          int temp=arr[min_index];
          arr[min_index]=arr[i];
          arr[i]=temp;
      }
  }
}
int main()
{
  int arr[]={6,2,1,9,19,3,20};
  int n = sizeof(arr)/sizeof(arr[0]);
  selectionSort(arr,n);
  print_arr(arr,n);
}
