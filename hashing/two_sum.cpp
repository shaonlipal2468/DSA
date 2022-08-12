#include<bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    int i,target_new;
    vector<int> ans;
    unordered_map<int, int> umap;
    unordered_map<int, int>::iterator it;

    int length = nums.size();
    for(int i=0;i<length;i++)
        umap[nums[i]]=i;
     for(i=0;i<length;i++)
     {
            target_new = target - nums[i];
            it = umap.find(target_new);
            if(it!=umap.end() && i!=it->second)
                  {
                      ans.push_back(i);
                      ans.push_back(it->second);
                      break;
                    }
     }
    return ans;
  }

int main(){
vector<int> nums = {2,5,5,11};
int target = 10;
vector<int> ans =  twoSum(nums,target);
for(int i=0; i < ans.size(); i++)
      cout << ans.at(i) << ' ';
}
