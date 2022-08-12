//journey to the moon hackerrank
#include<bits/stdc++.h>
using namespace std;


void dfs(vector<int> mat[],int src,vector<int> &visited,int &counter)
{
  visited[src]=1;
  counter++;
  for(auto neighbour : mat[src])
  {
    if(visited[neighbour]==0)
       dfs(mat,neighbour,visited,counter);
  }
}

int main()
{
  int n,p;
  cin>>n>>p;
  //adjacency matrix
  vector<int> mat[n];
  for(int i=0;i<p;i++)
  {
    int x,y;
    cin>>x>>y;
    mat[x].push_back(y);
    mat[y].push_back(x);
  }

  //dfs
  vector<int> temp,visited(n,0);
  for(int i=0;i<n;i++)
  {
    if(visited[i]==0)
    {
        int counter =0;
        dfs(mat,i,visited,counter);
        temp.push_back(counter);
    }
  }
  int total_possible = n*(n-1)/2;
  int not_included =0;
  for(int i=0;i<temp.size();i++)
      not_included+=(temp[i]*(temp[i]-1))/2;

  cout<< total_possible-not_included<<endl;
}
