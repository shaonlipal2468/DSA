#include<bits/stdc++.h>
using namespace std;
int fun(vector<int> &arr,int index,vector<int> &dp)
{
    if(index==0)
        return 0;
    if(index==1)
        return abs(arr[1]-arr[0]);
    if(dp[index]!=-1)
        return dp[index];
    int left = fun(arr,index-1,dp)+abs(arr[index]-arr[index-1]);
    int right=fun(arr,index-2,dp)+abs(arr[index]-arr[index-2]);
    return dp[index]= min(left,right);  
}
int main()
{
   vector<int> heights = {30,10,60,10,60,50};
   int n = heights.size();
   vector<int> dp(n,-1);
   cout<<fun(heights,n-1,dp);
}
