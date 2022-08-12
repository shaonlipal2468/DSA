// Max Sum Subarray of size K 

#include<bits/stdc++.h> 
using namespace std; 
//brute force method
int maximumSumSubarray_bruteforce(int arr[],int n,int k){
	int res=INT_MIN;
	for(int i=0;i<=n-k;i++)
	{
		int sum=0;
		for(int j=i;j<i+k;j++)
		{
			sum+=arr[j];
		}
		res= max(sum,res);
	}
	return res;	
}


//sliding window method
    int maximumSumSubarray(int arr[],int n,int k){
        // code here 
    int res = 0;
    for (int i=0; i<k; i++)
       res += arr[i];
    int curr_sum = res;
    for (int i=k; i<n; i++)
    {
       curr_sum += arr[i] - arr[i-k];
       res = max(res, curr_sum);
    }
  
    return res;
    }
    
int main()
{
	int arr[]={100,200,300,400};
	int n=sizeof(arr)/sizeof(arr[0]);
	int k=2;
	cout<<maximumSumSubarray_bruteforce(arr,n,k);
}
