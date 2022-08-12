#include<bits/stdc++.h>
using namespace std;
void print_vector(vector<vector<int>>& intervals)
{
  for(int i=0;i<intervals.size();i++)
  {
    cout<<"["<<intervals[i][0]<<","<<intervals[i][1]<<"]"<<endl;
  }
  cout<<endl<<endl;
}

//TLE
vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<=1)
            return intervals;
        sort(intervals.begin(),intervals.end());

        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i-1][1] >= intervals[i][0])
            {
                int b = max(intervals[i-1][1],intervals[i][1]);
                int a = intervals[i-1][0];

                intervals.erase(intervals.begin()+i-1);
                intervals.erase(intervals.begin()+i-1);
                intervals.insert(intervals.begin() + i-1,
                                 {a,b});
                i--;

            }

        }
        return intervals;
  }

vector<vector<int>> merge_new(vector<vector<int>>& intervals) {
  if(intervals.size()<=1)
      return intervals;
  sort(intervals.begin(),intervals.end());

  int index=0;
  for(int i=1;i<intervals.size();i++)
  {
    if(intervals[index][1] >= intervals[i][0])
        intervals[index][1] = max(intervals[index][1],intervals[i][1]);
    else{
      index++;
      intervals[index][0] = intervals[i][0];
      intervals[index][1] = intervals[i][1];
    }
  }
  int times = intervals.size()-1-index;
  for(int x=0;x<times;x++)
    intervals.pop_back();
  return intervals;
}


  int main()
  {
    vector<vector<int>> v;
    v.push_back({1,3});
    v.push_back({2,6});
    v.push_back({8,10});
    v.push_back({15,18});

    vector<vector<int>> ans =merge_new(v);
    print_vector(ans);
  }
