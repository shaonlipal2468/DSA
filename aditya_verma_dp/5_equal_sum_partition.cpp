#include<bits/stdc++.h>
using namespace std;
bool subset_sum(vector<int>& nums,int n,int sum)
{
    bool t[n+1][sum+1];
    int i,j;
    for(i=0;i<=sum;i++)
        t[0][i]=false;
    for(i=0;i<=n;i++)
        t[i][0]=true;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=sum;j++)
        {
            if(nums[i-1]>j)
                t[i][j]=t[i-1][j];
            else
                t[i][j]= t[i-1][j] || t[i-1][j-nums[i-1]];
        }
    }
    return t[n][sum];

}

bool equal_sum_partition(vector<int>& nums) {

    int sum =0;
    for(int i=0;i<nums.size();i++)
        sum+=nums[i];
    if(sum%2!=0)
        return false;
    else
        return subset_sum(nums,nums.size(),sum/2);

}


int main()
{
 vector<int> nums= {10,20,3,4,7,20};
 int n = nums.size();
 if (equal_sum_partition(nums) == true)
     cout<<"Equal sum partition possible"<<endl;
 else
     cout<<"Equal sum partition not possible"<<endl;
 return 0;
}
