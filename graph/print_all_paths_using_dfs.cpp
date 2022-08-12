#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[],int src,int dest)
{
    adj[src].push_back(dest);
}
void print_arr(vector<int> arr)
{
  for(int i=0;i<arr.size();i++)
     cout<<arr[i]<<" ";
  cout<<endl;
}
void print_all_paths_util(vector<int> adj[],int u,int dest,int v,vector<bool> &visited,vector<int> &path)
{
  visited[u]= true;
  path.push_back(u);
  if(u==dest)
     print_arr(path);
  else
  {
      for(auto neighbour : adj[u])
      {
        if(!visited[neighbour])
            print_all_paths_util(adj,neighbour,dest,v,visited,path);
      }
  }
  path.pop_back();
  visited[u]=false;
}
void print_all_paths(vector<int> adj[],int src,int dest,int v)
{
    vector<bool> visited(v,false);
    vector<int> path;
    print_all_paths_util(adj,src,dest,v,visited,path);
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
   print_all_paths(adj,src,dest,v);
}
