#include<bits/stdc++.h>
using namespace std;
//dynamic programming - order of n2
void min_jumps(int arr[],int n)
{
    int dp[n];
    dp[n-1]=0;
    for(int i=n-2;i>=0;i--)
    {
        int steps=arr[i];
        if(steps==0)
             dp[i]=-1;
        else
        {
            int min=INT_MAX;
            for(int j=1;j<=steps && i+j<n;j++)
                if(dp[i+j]!=-1 && dp[i+j]<min)
                   min=dp[i+j];
            if(min!=INT_MAX)
                dp[i] = min+1;
            else
                dp[i]=-1;
        }
    }
    cout<<dp[0];
}
//order of n
int minJumps(int arr[], int n){
    // Your code here
if (n <= 1)
    return 0;
if (arr[0] == 0)
    return -1;

int maxReach = arr[0];
int step = arr[0];
int jump = 1;

int i;
for (i = 1; i < n; i++)
{
    if (i == n - 1)
        return jump;
    maxReach = max(maxReach, i + arr[i]);
    step--;
    if (step == 0)
      {

        jump++;
        if (i >= maxReach)
            return -1;
        step = maxReach - i;
      }
}

return -1;
}
int main()
{
    //int arr[]={3,3,0,2,1,2,4,2,0,0};
    int arr[]={1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    min_jumps(arr,n);

}
