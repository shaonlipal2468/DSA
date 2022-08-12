#include<bits/stdc++.h>
using namespace std;
void print_array(vector<string> &arr)
{
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void print_map(unordered_map<string,set<string>> m)
{
  for(auto m1:m)
  {
     cout<<m1.first<<" -> ";
     for(auto m2:m1.second)
        cout<<m2<<" ";
     cout<<endl<<endl;
  }
}

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>> m;
        stack<string> s;
        for(int i=0;i<tickets.size();i++)
        {
            string src= tickets[i][0];
            string dest = tickets[i][1];
            m[src].insert(dest);
        }
        vector<string> ans;
        s.push("JFK");
        while(!s.empty())
        {
           string src = s.top();
           if(m[src].size()==0)
           {
             ans.push_back(src);
             s.pop();
           }
           else
           {
             auto dst = m[src].begin();
             s.push(*dst);
             m[src].erase(dst);
           }
        }
        reverse(ans.begin(),ans.end());

        return ans;
    }

int main()
{
   // vector<vector<string>> tickets{{"JFK","SFO"},
   //                                           {"JFK","ATL"},
   //                                           {"SFO","ATL"},
   //                                           {"ATL","JFK"},
   //                                           {"ATL","SFO"}};

   vector<vector<string>> tickets{{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
    vector<string> ans = findItinerary(tickets);
    print_array(ans);



}
