#include <bits/stdc++.h>
using namespace std;
bool two_sum_brute_force(int arr[],int n,int x)
{
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]+arr[j]==x)
			   return true;
		}
	}
	return false;
}

bool binary_search(int arr[],int start,int end,int search)
{
	while(start<=end)
	{
	   int middle = start+(end-start)/2;
       if(arr[middle] == search)
          return true;	
        else if(arr[middle]>search)
            end = middle-1;
        else 
            start=middle+1;			
		
    }
	return false;
}

bool two_sum_binary_search(int arr[],int n,int x)
{
	sort(arr,arr+n);
    int low=0,high=n-1;
    for(int i=0;i<n;i++)
    {
    	if(binary_search(arr,i+1,n-1,x-arr[i] )==true)
    	   return true;
	}
	return false;
	}

bool two_sum(int arr[],int n,int x){
    sort(arr,arr+n);
    int low=0,high=n-1;
    
    while(low<high)
    {
        if(arr[low]+arr[high]<x)
           low++;
        else if(arr[low]+arr[high]>x)
           high--;
        else if(arr[low]+arr[high]==x)
           return true;
           
    }
    return false;
}
int main()
{
   int arr[]={44,3,2,89,99,30};
   int n=sizeof(arr)/sizeof(arr[0]);
   
   int x=130;
   cout<<two_sum_binary_search(arr,n,x);
   
   return 0;
}
