#include<bits/stdc++.h>
using namespace std;

void util(vector<int> adj[],vector<int> &visited,int src,stack<int> &s)
{
  visited[src]=1;

  for(auto x: adj[src])
  {
    if(visited[x]==false)
        util(adj,visited,x,s);
  }
  s.push(src);
}

vector<int> topological_sort(vector<int> adj[],int v)
{
    // code here
  vector<int> visited(v,false);
    stack<int> s;
    for(int i=0;i<v;i++)
    {
      if(visited[i]==false)
        util(adj,visited,i,s);
    }
    vector<int> ans;

    while(s.size()>0)
    {
      ans.push_back(s.top());
      s.pop();
    }
    return ans;
}


void addEdge(vector<int> adj[],int u,int v)
{
  adj[u].push_back(v);
}

int main()
{
  int v=6;
  vector<int> adj[v];
  addEdge(adj,5, 2);
  addEdge(adj,5, 0);
  addEdge(adj,4, 0);
  addEdge(adj,4, 1);
  addEdge(adj,2, 3);
  addEdge(adj,3, 1);
  vector<int> sorting = topological_sort(adj,v);

  for(int i=0;i<sorting.size();i++)
     cout<<sorting[i]<<" ";
  cout<<endl;
}
