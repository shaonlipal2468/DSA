
#include <bits/stdc++.h>
using namespace std;
    long long int merge(long long arr[],long long temp[],long long low,
    long long mid,long long high)
{
    long long int i,j,k,inversion=0;
    i=low;
    k=low;
    j=mid+1;

    while(i<=mid && j<=high)
    {
        if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
        //inversion possible here
        else{
            temp[k++]= arr[j++];
            inversion+=mid-i+1;
        }
    }

    while(i<=mid)
       temp[k++]=arr[i++];

     while(j<=high)
       temp[k++]=arr[j++];

    for(long long int x=low;x<=high;x++)
        arr[x]=temp[x];
    return inversion;


}
long long int mergesort(long long arr[],long long temp[],long long low,long long high)
{
    long long int mid,inversion=0;
    if(low<high)
    {
        mid=(low+high)/2;
        inversion+= mergesort(arr,temp,low,mid);
        inversion+= mergesort(arr,temp,mid+1,high);
        inversion+= merge(arr,temp,low,mid,high);
    }
    return inversion;
}

    long long int inversionCount(long long arr[], long long n)
    {
        // Your Code Here
        long long int temp[n];
        return mergesort(arr,temp,0,n-1);
  }

int main()
{
  long long int arr[]={2,3,1,6,5};
  long long int n= sizeof(arr)/sizeof(arr[0]);
  cout<<inversionCount(arr,n);
}
