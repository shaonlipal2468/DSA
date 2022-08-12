#include<bits/stdc++.h>
using namespace std;

int countTriplets(int arr[], int n, int sum)
{
    // Your code goes here
    int count=0;
    sort(arr,arr+n);
    for(int i=0;i<n-2;i++)
    {
        int low = i+1;
        int high = n-1;

        while(low<high)
        {
            int sum_triplet = arr[i]+arr[low]+arr[high];
            if(sum_triplet< sum)
            {
                count=count+(high-low);
                low++;
            }
            else
               high--;
        }
    }
    return count;
}

int main()
{
int arr[] = {-2, 0, 1, 3};
int n = sizeof(arr)/sizeof(arr[0]);
int sum =2;
cout<<countTriplets(arr,n,sum)<<endl;
}
