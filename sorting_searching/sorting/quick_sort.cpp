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
void quicksort(int arr[],int low,int high)
{
    int pivot;
    if(low<high)
    {
        pivot = partition(arr,low,high);
        quicksort(arr,low,pivot-1);
        quicksort(arr,pivot+1,high);
    }
}
int main()
{
  int arr[]={6,2,1,9,19,3,20};
  int n= sizeof(arr)/sizeof(arr[0]);
  quicksort(arr,0,n-1);
  for(int x=0;x<n;x++)
    cout<<arr[x]<<" ";
  cout<<endl;
}
