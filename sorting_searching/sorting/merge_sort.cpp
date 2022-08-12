#include <bits/stdc++.h>
using namespace std;
 void merge(int arr[],int temp[],int low,int mid,int high)
{
    int i,j,k;
    i=low;
    k=low;
    j=mid+1;

    while(i<=mid && j<=high)
    {
        if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
        else
            temp[k++]= arr[j++];
    }
    while(i<=mid)
       temp[k++]=arr[i++];

     while(j<=high)
       temp[k++]=arr[j++];

    for(int x=low;x<=high;x++)
        arr[x]=temp[x];
}
void mergesort(int arr[],int temp[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(arr,temp,low,mid);
        mergesort(arr,temp,mid+1,high);
        merge(arr,temp,low,mid,high);
    }
}

int main()
{
  int arr[]={3,2,6,1,8,9,5,10};
  int n= sizeof(arr)/sizeof(arr[0]);
  int temp[n];
  mergesort(arr,temp,0,n-1);

  for(int x=0;x<n;x++)
    cout<<arr[x]<<" ";
  cout<<endl;

}
