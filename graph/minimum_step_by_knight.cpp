#include<bits/stdc++.h>
using namespace std;
// void print_arr(vector<pair<int,int>> path)
// {
//    for(auto x:path)
//       cout<<"("<<x.first<<","<<x.second<<")"<<endl;
//    cout<<endl;
// }
bool isSafe(int i,int j,int n,vector<vector<int>> &arr)
{
   if(i>=0 && i<n && j>=0 && j<n && arr[i][j]==0)
       return true;
   return false;
}

void goDirection(int x1,int y1,int x2,int y2,vector<vector<int>> &arr,queue<pair<int,int>> &q,int n)
{
  if(isSafe(x2,y2,n,arr))
  {
    //  cout<<x2+1<<" "<<y2+1<<"safe"<<endl;
      arr[x2][y2] = arr[x1][y1]+1;
      q.push({x2,y2});
  }
//  cout<<x2+1<<" "<<y2+1<<"not safe "<<endl;
}

int minimum_step_by_knight(int n,int initial[],int final[])
{
    int x1= initial[0]-1;
    int y1= initial[1]-1;
    int x2= final[0]-1;
    int y2= final[1]-1;
    vector<vector<int>> arr(n,vector<int> (n,0));
    if(x1==x2 && y1==y2)
       return 0;
    queue<pair<int,int>> q;
    q.push({x1,y1});
    while(!q.empty())
    {
        auto curr = q.front();

        q.pop();
        int i = curr.first;
        int j = curr.second;
        if(i==x2 && j==y2)
             return arr[i][j];

        goDirection(i,j,i-2,j+1,arr,q,n);
        goDirection(i,j,i-1,j+2,arr,q,n);
        goDirection(i,j,i+1,j+2,arr,q,n);
        goDirection(i,j,i+2,j+1,arr,q,n);
        goDirection(i,j,i+2,j-1,arr,q,n);
        goDirection(i,j,i+1,j-2,arr,q,n);
        goDirection(i,j,i-1,j-2,arr,q,n);
        goDirection(i,j,i-2,j-1,arr,q,n);
    }
    return -1;
}

int main()
{
    int n=3;
    int initial[2]= {1,1};
    int final[2]={3,3};
    cout<<minimum_step_by_knight(n,initial,final);
}
