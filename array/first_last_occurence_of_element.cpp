#include<bits/stdc++.h>
using namespace std;

struct occurence{
	int first;
	int last;
};
struct occurence first_last(int arr[],int low,int high,int search)
{
	struct occurence o;
	o.first = o.last=-1;
	int start=low,end=high;
	while(start<=end)
	{
	   int middle = start+(end-start)/2;

        if(arr[middle]>search)
            end = middle-1;
        else if(arr[middle]<search)
            start=middle+1;
	    else if(arr[middle]==search)
		    {
		       	if(middle != 0 && arr[middle]==arr[middle-1])
		       	  end=middle-1;
		       	else{
		       		 o.first=middle;
		       		 break;
				   }
			}

    }

    start=low,end=high;
    while(start<=end)
	{
	   int middle = start+(end-start)/2;

        if(arr[middle]>search)
            end = middle-1;
        else if(arr[middle]<search)
            start=middle+1;
	    else if(arr[middle]==search)
		    {
		       	if(middle != high && arr[middle]==arr[middle+1])
		       	  start=middle+1;
		       	else{
		       		 o.last=middle;
		       		 break;
				   }
			}

    }
	return o;
}


int main()
{
	//int arr[]={1,2,2,3,3,4,4,4,4,5};
	int arr[]={2,2};
	int n=sizeof(arr)/sizeof(arr[0]);

	struct occurence o;
	o= first_last(arr,0,n-1,2);
	cout<<o.first<<" "<<o.last<<endl;


}
