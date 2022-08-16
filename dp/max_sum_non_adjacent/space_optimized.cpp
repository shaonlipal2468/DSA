#include<bits/stdc++.h>
using namespace std;

int maximumNonAdjacentSum(vector<int> &nums)
{  
    int n = nums.size();
    
    
    int prev2 =nums[0];
    int prev1 = max(nums[0],nums[1]);
    
    for(int i=2;i<n;i++)
    {
        int pick = nums[i]+prev2;
        int non_pick = prev1;
        int curr=max(pick,non_pick);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}


int main()
{
   vector<int> nums={2,1,4,9};
   cout<<maximumNonAdjacentSum(nums);
}   
