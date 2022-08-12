#include<bits/stdc++.h>
using namespace std;

    vector<vector<string>> groupStrings(vector<string> &strings) {
        // write your code here
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> big_map;
        for(auto str:strings)
        {
            int n = str.size();
            if(n==1)
               big_map[""].push_back(str);
            else
            {
              string key;
               for(int i=1;i<n;i++)
                {
                    int flag = str[i]-str[i-1];
                    if(flag<0)
                    flag+=26;
                    key.append(to_string(flag));
                    key.append("#");
                }
                big_map[key].push_back(str);
            }
        }
        for(auto x:big_map)
            ans.push_back(x.second);
        return ans;
    }

int main()
{
   vector<string> str{"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"};
   vector<vector<string>> ans =groupStrings(str);
   for(int i=0;i<ans.size();i++)
   {
     for(int j=0;j<ans[i].size();j++)
        cout<<ans[i][j]<<" ";
     cout<<endl;
   }


   return 0;
}
