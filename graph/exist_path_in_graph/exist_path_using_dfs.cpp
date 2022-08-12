#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[],int src,int dest)
{
    adj[src].push_back(dest);
}
void util(vector<int> adj[],int u,int dest,int v,vector<bool> &visited,bool &exists)
{
  visited[u]= true;
  if(u==dest)
  {
    exists = true;
    return;
  }
  for(auto neighbour : adj[u])
    if(!visited[neighbour])
        util(adj,neighbour,dest,v,visited,exists);
}

bool haspath(vector<int> adj[],int src,int dest,int v)
{
  bool exists = false;
  vector<bool> visited(v,false);
  util(adj,src,dest,v,visited,exists);
  return exists;
}
int main()
{
   int v=8;
   vector<int> adj[v];
   addEdge(adj,0,3);
   addEdge(adj,3,5);
   addEdge(adj,1,0);
   addEdge(adj,3,4);
   addEdge(adj,4,3);
   addEdge(adj,5,6);
   addEdge(adj,1,4);
   addEdge(adj,4,6);
   addEdge(adj,1,2);
   addEdge(adj,6,7);
   addEdge(adj,2,7);
   int src = 0;
   int dest = 7;
   cout<<haspath(adj,src,dest,v);

}
