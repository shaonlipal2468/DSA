//https://medium.com/swlh/merge-two-sorted-arrays-without-extra-space-efficiently-o-1-gap-method-detailed-simplified-57a336146601
#include<bits/stdc++.h>
using namespace std;
void print_arr(int arr[],int size)
{
  for(int i=0;i<size;i++)
     cout<<arr[i]<<" ";
  cout<<endl;
}
int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}

void util(int *arr1,int *arr2,int n ,int m,int gap)
{
    int i,j;
    // comparing elements in the first array.
     for (i = 0; i + gap < n; i++)
        if (arr1[i] > arr1[i + gap])
             swap(arr1[i], arr1[i + gap]);
    // comparing elements in both arrays.
    for (j = gap > n ? gap - n : 0; i < n && j < m; i++, j++)
        if (arr1[i] > arr2[j])
           swap(arr1[i], arr2[j]);
    if (j < m)
    {
     // comparing elements in the second array.
    for (j = 0; j + gap < m; j++)
        if (arr2[j] > arr2[j + gap])
              swap(arr2[j], arr2[j + gap]);
     }
}

void gap_method(int arr1[],int arr2[],int n,int m)
{
    int i,j;
    int gap = ceil((m+n)/2);
    while(gap!=0)
    {
        util(arr1,arr2,n,m,gap);
        gap=nextGap(gap);
    }
    print_arr(arr1,n);
    print_arr(arr2,m);

}
int main()
{
  int arr1[] = {1, 3, 5, 7},  arr2[] = {0, 2, 6, 8, 9};
  // int arr1[]={2, 3, 7, 8, 14, 16};
  // int arr2[]={5,8};
  int n =sizeof(arr1)/sizeof(arr1[0]);
  int m =sizeof(arr2)/sizeof(arr2[0]);
  gap_method(arr1,arr2,n,m);

}
