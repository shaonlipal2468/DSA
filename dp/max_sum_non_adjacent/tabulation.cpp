#include<bits/stdc++.h>
using namespace std;

int maximumNonAdjacentSum(vector<int> &nums)
{  
    int n = nums.size();
    vector<int> dp(n);
    
    dp[0]=nums[0];
    dp[1] = max(nums[0],nums[1]);
    
    for(int i=2;i<n;i++)
    {
        int pick = nums[i]+dp[i-2];
        int non_pick = dp[i-1];
        dp[i]=max(pick,non_pick);
    }
    return dp[n-1];
}


int main()
{
   vector<int> nums={2,1,4,9};
   cout<<maximumNonAdjacentSum(nums);
}   
