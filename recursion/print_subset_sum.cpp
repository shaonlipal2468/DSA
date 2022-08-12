#include<bits/stdc++.h>
using namespace std;

void util(vector<int> input,vector<int> &output,vector<int> &ans,int index,int sum,int n)
{
    if (index>=n)
    {
        ans.push_back(sum);
        return;
    }
    output.push_back(input[index]);
    util(input,output,ans,index+1,sum+input[index],n);
    
    output.pop_back();
    util(input,output,ans,index+1,sum,n);
}
vector<int> subsetSums(vector<int> input, int n)
{
    // Write Your Code here
    vector<int> ans,output;
    int index=0,sum=0;
    util(input,output,ans,index,sum,n);
    sort(ans.begin(),ans.end());
    return ans;
}
int main()
{
    vector<int> arr={2,3};
    vector<int> output = subsetSums(arr,2);
    for(int i=0;i<output.size();i++)
       cout<<output[i]<<"\t";
    cout<<endl;
    exit(0);
}