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
        unordered_map<string,set<string>> m;
        for(int i=0;i<tickets.size();i++)
        {
            string src= tickets[i][0];
            string dest = tickets[i][1];
            m[src].insert(dest);

        }

      // for(auto m1:m)
      // {
      //    cout<<m1.first<<" -> ";
      //    for(auto m2:m1.second)
      //       cout<<m2<<" ";
      //    cout<<endl;
      // }

        vector<string> ans;
        string source = "JFK";
        ans.push_back(source);
        while(m.size()>0)
        {
            if(m.find(source)!=m.end() && m[source].size()>0)
            {

                auto it =m[source].begin();
                string temp = *it;
                ans.push_back(*it);
                m[source].erase(it);
                if(m[source].size()==0)
                {
                  m.erase(source);
                  print_map(m);
                }
                source=temp;
            }
        }
        print_array(ans);

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
    //print_array(ans,5);



}
