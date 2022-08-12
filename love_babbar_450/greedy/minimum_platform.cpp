#include<bits/stdc++.h>
using namespace std;

int findPlatform(int arr[], int dep[], int n)
  {
    // Your code here
    sort(arr,arr+n);
    sort(dep,dep+n);

    int i=1,j=0;
    int max_platform =1,platform_needed_now=1;

    while(i<n && j<n)
    {
        if(arr[i]<=dep[j])
        {
            platform_needed_now++;
            i++;
        }
        else if(arr[i]>dep[j])
        {
            platform_needed_now--;
            j++;
        }
        max_platform = max(max_platform,platform_needed_now);
    }
    return max_platform;
  }

  int main()
  {
     int arr[] = {0900, 0940, 0950, 1100, 1500, 1800};
     int dep[] = {0910, 1200, 1120, 1130, 1900, 2000};
     int n=sizeof(arr)/sizeoff(arr[0]);
     cout<<findPlatform(arr,dep,n);
  }
