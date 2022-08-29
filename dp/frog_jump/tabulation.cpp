#include<bits/stdc++.h>
using namespace std;
int fun(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n);
    dp[0]=0;
    dp[1]= abs(arr[1]-arr[0]);
    for(int i=2;i<n;i++)
    {
       int left = dp[i-1]+abs(arr[i]-arr[i-1]);
       int right = dp[i-2]+abs(arr[i]-arr[i-2]);
       dp[i]= min(left,right);
    }
    
    return dp[n-1];
}

int main()
{
   vector<int> heights = {30,10,60,10,60,50};
   cout<<fun(heights);
}
