#include<bits/stdc++.h>
using namespace std;

//aabc  a#bb

string answer(string stream)
{
      unordered_map<char,int> m;
      vector<char> history;
      string ans="";
      history.push_back(stream[0]);
      ans.push_back(stream[0]);
      m[stream[0]]++;

      for(int i=1;i<stream.size();i++)
      {
         m[stream[i]]++;
         if(m[stream[i]]==1)
         {
           history.push_back(stream[i]);
         }
         else if(m[stream[i]]>1)
         {
            int index;
            for(int x=0;x<history.size();x++)
               {
                 if(history[x]==stream[i])
                  {
                    index=x;
                    history.erase(history.begin()+x);
                    break;
                  }
               }
         }

         if(history.size())
            ans.push_back(history[0]);
         else
            ans.push_back('#');

      }
      return ans;
}

int main()
{
   string stream ="hrqcvsvszpsjammdrw";
  // string stream ="aabc";

   string ans =answer(stream);
   cout<<ans<<endl;
}
