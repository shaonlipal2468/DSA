#include<bits/stdc++.h>
using namespace std;    

void util(int index,int target,vector<int> &input,vector<int> &output,vector<vector<int>> &ans)
    {
        if(index==input.size())
        {
            if(target==0)
                ans.push_back(output);
            return;
        }
        else if(input[index]<=target)
        {
            output.push_back(input[index]);
            util(index,target-input[index],input,output,ans);
            output.pop_back();
            
        }
        util(index+1,target,input,output,ans);
        
        
    }
    vector<vector<int>> combinationSum(vector<int>& input, int target) {
        int index=0,sum=0;
        vector<vector<int>> ans;
        vector<int> output;
        util(index,target,input,output,ans);
        return ans;
        
    }
void print(vector<int> arr)
{
   for(int i=0;i<arr.size();i++)
     cout<<arr[i]<<" ";
   cout<<endl;
}

int main()
{
   vector<int> input ={2,3,6,7};
   int target =7;
   vector<vector<int>> ans = combinationSum(input,target);
   for(int i=0;i<ans.size();i++)
      print(ans[i]);
}
   

