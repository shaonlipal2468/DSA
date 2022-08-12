#include <bits/stdc++.h>
using namespace std;

//here order is not maintained
// idea is to use partition algorithm of quick sort where
//pivot =0 will be used
//less than pivot value will be in the left part and positive numbers will be at the right side
//Time complexity O(n) and space complexity O(1)
void rearrange(int arr[],int low,int high)
{
	int pivot=0;
	int i=low-1;
	for(int j=low;j<high;j++)
	{
		if(arr[j]<=pivot)
		   {
		   	 i++;
		   	 swap(arr[i],arr[j]);
		   }
	}
}
void two_pointer_method(int arr[],int n)
{
    int low=0;
    int high= n-1;
    while(low<=high)
    {
         if(arr[low]>0 && arr[high]<0)
         {
            swap(arr[low],arr[high]);
            low++;
            high--;
         }

         else if (arr[low]<0 && arr[high]<0)
            low++;
         else if (arr[low]>0 && arr[high]>0)
            high--;
         else if(arr[low]<0 && arr[high]>0)
         {
             low++;
             high--;
         }
    }
}

void print_arr(int arr[],int n)
{
	for(int i=0;i<n;i++)
	   cout<<arr[i]<<" ";
	cout<<endl;
}

int main()
{
	int arr[]={-1,23,-1,3,-2,56,99};
	int n=sizeof(arr)/sizeof(arr[0]);
	rearrange(arr,0,n-1);
	print_arr(arr,n);
}
