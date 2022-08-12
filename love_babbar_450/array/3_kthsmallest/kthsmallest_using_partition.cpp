#include <bits/stdc++.h>

using namespace std;
int partition(int arr[],int low,int high)
{
	int pivot=arr[high];
	int i=low-1;
	for(int j=low;j<high;j++)
	{
		if(arr[j]<=pivot)
		   {
		   	 i++;
		   	 swap(arr[i],arr[j]);
		   }
	}
	swap(arr[i+1],arr[high]);
	return i+1;
}

int kthsmallest(int arr[],int low,int high,int k)
{
    int pivot=partition(arr,low,high);
    if(k>pivot)
       kthsmallest(arr,pivot+1,high,k);
    
    else if(k<pivot)
       kthsmallest(arr,low,pivot-1,k);
    
    else return pivot;
}
int main()
{
   int arr[]={2,4,5,1,9,99};
   int n=sizeof(arr)/sizeof(arr[0]);
   
   int k=3;
   int index=kthsmallest(arr,0,n-1,k-1);
   cout<<arr[index];
   
   return 0;
}
