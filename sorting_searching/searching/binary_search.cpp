#include<bits/stdc++.h>
using namespace std;
int binary_search_iterative(int arr[],int start,int end,int search)
{
	while(start<=end)
	{
	   int middle = start+(end-start)/2;
       if(arr[middle] == search)
          return middle;
        else if(arr[middle]>search)
            end = middle-1;
        else
            start=middle+1;

    }
	return -1;
}

int binary_search_recursive(int arr[],int start,int end,int search)
{
	if(start<=end)
	{
	   int middle = start+(end-start)/2;
        if(arr[middle] == search)
            return middle;
        else if(arr[middle]>search)
            binary_search_recursive(arr,start,middle-1,search);
        else
            binary_search_recursive(arr,middle+1,end,search);

    }
	return -1;
}


int main()
{
	int arr[]={4,5,6,7,0,1,2};
	int size=sizeof(arr)/sizeof(arr[0]);

	int found = binary_search_iterative(arr,0,size-1,0);
	if(found!=-1)
		cout<<"found at " <<found<<" index"<<endl;
	else
		cout<<"not found"<<endl;


	found = binary_search_recursive(arr,0,size-1,5);
	if(found!=-1)
		cout<<"found at " <<found<<" index"<<endl;
	else
		cout<<"not found"<<endl;
}
