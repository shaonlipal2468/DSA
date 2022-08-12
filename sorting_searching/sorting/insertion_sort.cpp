#include<bits/stdc++.h>
using namespace std;
void print_arr(int arr[],int n)
{
  for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";
  cout<<endl;
}

void insert(int arr[], int i)
  {
      int key = arr[i];
      int j=i-1;
      while(j>=0 && key<arr[j])

      for(j=i-1;j>=0 && key<arr[j];j--)
           arr[j+1]=arr[j];
      arr[j+1]=key;
  }
  void insertionSort(int arr[], int n)
  {
      for(int i=1;i<n;i++)
          insert(arr,i);
  }

  int main()
  {
    int arr[]={6,2,1,9,19,3,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr,n);
    print_arr(arr,n);
  }
