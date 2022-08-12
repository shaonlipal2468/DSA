#include <bits/stdc++.h>
using namespace std;

int trappingWater(int arr[], int n){
    // Code here

    int left[n];
    int right[n];

    left[0]=arr[0];
    for(int i=1;i<n;i++)
        left[i]=max(arr[i],left[i-1]);

    right[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--)
        right[i]=max(arr[i],right[i+1]);

    int ans =0;
    for(int i=0;i<n;i++)
       ans+= min(left[i],right[i])-arr[i];
    return ans;


}

int main()
{
int arr[] = {7,4,0,9};
int n= sizeof(arr)/sizeof(arr[0]);
cout<<trappingWater(arr,n)<<endl;
}
