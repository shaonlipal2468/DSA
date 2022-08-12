#include<bits/stdc++.h>
using namespace std;
int lis( int arr[], int n )
{
	int lis[n];
	lis[0] = 1;
  int ans =0;
	for (int i = 1; i < n; i++ )
	{
    int max_ = 0;
		for (int j = 0; j < i; j++ )
    {
         if ( arr[i] > arr[j])
         {
             if(lis[j]>max_)
                max_= lis[j];
         }
    }
    lis[i]=max_+1;
    ans = max(ans,lis[i]);


	}
	for(int i=0;i<n;i++)
	   cout<<lis[i]<<" ";
  cout<<endl;
	return ans;
}

int main()
{
	int arr[]={6,3,7,4,6,9};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout<<lis(arr,n)<<endl;

	reverse(arr,arr+n);
	cout<<lis(arr,n)<<endl;
}
