#include<bits/stdc++.h>
using namespace std;
int maximumNonAdjacentSum(vector<int> nums,int index,vector<int> &dp)
{
    if(index==0)
        return nums[0];
    else if(index<0)
        return 0;
        
     if(dp[index]!=-1)
        return dp[index];

     int pick = nums[index]+maximumNonAdjacentSum(nums,index-2,dp);
     int not_pick = maximumNonAdjacentSum(nums,index-1,dp);
     return dp[index]=max(pick,not_pick);
           
}

int main()
{
   vector<int> nums={2,1,4,9};
   int n = nums.size();
   vector<int> dp(n+1,-1);
   cout<<maximumNonAdjacentSum(nums,n-1,dp);
}   
