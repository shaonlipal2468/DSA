#include <bits/stdc++.h>
using namespace std;
static bool comparator(vector<int> &a,vector<int> &b)
   {
       if(a[1]<b[1])
          return true;
       else if(a[1]==b[1])
          return a[0]<b[0];
          return false;
   }
   int maxEvents(int start[], int end[], int n) {
       // code here
       int count=0;
         vector<vector<int>> v;
         // cout<<"hello"<<endl;
         for(int i=0;i<n;i++)
             v.push_back({start[i],end[i]});

         sort(v.begin(),v.end(),comparator);

         // for(int i=0;i<v.size();i++)
         // {
         //   cout<<v[i][0]<<" "<<v[i][1]<<endl;
         // }
         // cout<<endl;

         set<int> days;
         for(int i=1;i<=v[v.size()-1][1];i++)
            days.insert(i);

         for(const auto &event:v)
         {
             int s =event[0];
             int e= event[1];
             auto it = days.lower_bound(s);

             if(it==days.end() || *it>e)
                continue;
             else
             {
                 ++count;
                 days.erase(it);
             }
         }

         return count;
   }
 int main()
 {
   //int S[] = {1,4,2,3,1},F[] = {4,4,2,4,1};
   int S[]={1},F[]={1000};
   int n = sizeof(S)/sizeof(S[0]);

   cout<<maxEvents(S,F,n);
 }
