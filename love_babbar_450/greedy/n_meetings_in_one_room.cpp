#include <bits/stdc++.h>
using namespace std;
 bool comparator(pair<int,int> a, pair<int,int> b)
    {
        if(a.second == b.second)
           return a.first<b.first;
        else
           return a.second<b.second;
    }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.

    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        int count=0;
        int prev_selected,now_examing;
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++)
            v[i]={start[i],end[i]};

        sort(v.begin(),v.end(),comparator);

        //select the first element
        count++;
        prev_selected=0;
        //given that start time of one chosen meeting can't be equal to the end time of the other chosen meeting
        for(int now_examing=1;now_examing<n;now_examing++)
        {
            if(v[now_examing].first> v[prev_selected].second)
            {
                count++;
                prev_selected= now_examing;
            }
        }

        return count;
    }

    int main()
    {
      int n = 6,S[] = {1,3,0,5,8,5},F[] = {2,4,6,7,9,9};
      cout<<maxMeetings(S,F,n);
    }
