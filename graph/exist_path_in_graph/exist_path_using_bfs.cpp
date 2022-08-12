#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[],int src,int dest)
{
    adj[src].push_back(dest);
}
bool hasPath(vector<int> adj[],int src,int dest,int v)
{
  if(src==dest)
       return true;
  vector<bool> visited(v,false);
  visited[src]= true;
  queue<int> q;
  q.push(src);
  while(!q.empty())
  {
       int temp = q.front();
       q.pop();
       for(auto neighbour : adj[temp])
       {
           if(neighbour==dest)
               return true;
           if(!visited[neighbour])
           {
             visited[neighbour]=true;
             q.push(neighbour);
           }
       }
  }
  return false;
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
   cout<<hasPath(adj,src,dest,v);

}
