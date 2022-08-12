#include<bits/stdc++.h>
using namespace std;
void print_arr(int arr[],int size)
{
  for(int i=0;i<size;i++)
     cout<<arr[i]<<" ";
  cout<<endl;
}
//O(mn) solution
void insertion(int *arr2,int m)
{
  int first= arr2[0],k;
  for(k=1;k<m && first> arr2[k];k++)
       arr2[k-1]=arr2[k];
  arr2[k-1] =first;
}
void merge_inplace(int arr1[],int arr2[],int n,int m)
{
  for(int i=0;i<n;i++)
  {
      if(arr1[i]>arr2[0])
      {
         swap(arr1[i],arr2[0]);
         insertion(arr2,m);
      }
  }
}
int main()
{
  //int arr1[] = {1, 3, 5, 7},  arr2[] = {0, 2, 6, 8, 9};
  int arr1[]={2, 3, 7, 8, 14, 16};
  int arr2[]={5,8};
  int n =sizeof(arr1)/sizeof(arr1[0]);
  int m =sizeof(arr2)/sizeof(arr2[0]);
  merge_inplace(arr1,arr2,n,m);
  print_arr(arr1,n);
  print_arr(arr2,m);
}
