#include<bits/stdc++.h>
using namespace std;
int maximumNonAdjacentSum(vector<int> nums,int index)
{
    if(index==0)
        return nums[0];
    else if(index<0)
        return 0;

     int pick = nums[index]+maximumNonAdjacentSum(nums,index-2);
     int not_pick = maximumNonAdjacentSum(nums,index-1);
     return max(pick,not_pick);
           
}

int main()
{
   vector<int> nums={2,1,4,9};
   int n = nums.size();
   cout<<maximumNonAdjacentSum(nums,n-1);
}   
