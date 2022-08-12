#include <bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
  vector<int> ans;
          for(int i=0;i<nums.size();i++)
          {
              int index= abs(nums[i])-1;
              if(nums[index]<0)
                  ans.push_back(abs(nums[i]));
              nums[index] = -nums[index];

          }
          return ans;
    }

int main()
{
  vector<int> nums = {4,3,2,7,8,2,3,1};
  vector<int> ans =findDuplicates(nums);

  for(int i=0;i<ans.size();i++)
     cout<<ans[i]<<" ";
  cout<<endl;

}
