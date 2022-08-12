#include<bits/stdc++.h>
using namespace std;
enum Color {black,white,grey};
void addEdge(vector<int> adj[],int src,int dest)
{
  adj[src].push_back(dest);
}
bool util(vector<int> adj[],int curr,vector<int> &color)
{
    //move element from white set to grey set
    color[curr]=grey;
    for(auto neighbour : adj[curr])
    {
       //if in grey set then cycle exists
       if(color[neighbour]==grey)
               return true;
       if(util(adj,neighbour,color))
               return true;
    }
    //exploration done - move vertex from grey set to black set
    color[curr]=black;
    return false;
}
bool detect_cycle_directed_graph(int v,vector<int> adj[])
{
     vector<int> color(v,white);
     for(int i=0;i<v;i++)
        if(color[i]== white)
            if(util(adj,i,color))
                return true;
     return false;
}
int main()
{
  int v=6;
  vector<int> adj[v];
  addEdge(adj,0,1);
  addEdge(adj,1,2);
  addEdge(adj,0,2);
  addEdge(adj,0,3);
  addEdge(adj,3,4);
  addEdge(adj,4,5);
  addEdge(adj,5,3);
  cout<<detect_cycle_directed_graph(v,adj);
}
