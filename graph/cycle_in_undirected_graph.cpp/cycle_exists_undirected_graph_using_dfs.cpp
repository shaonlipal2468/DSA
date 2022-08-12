#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
bool util(int src,vector<bool> &visited,vector<int> adj[],int parent)
    {
        visited[src]=true;
        for(auto neighbour: adj[src])
        {
             if(!visited[neighbour])
              {
                if(util(neighbour,visited,adj,src))
                    return true;
              }
             else
             {
               if(neighbour!=parent)
                  return true;
             }
        }
        return false;
    }
	//Function to return a list containing the DFS traversal of the graph.
bool cycle_Exists(vector<int> adj[],int v)
	{
	    vector<bool> visited(v,false);
	    for(int i=0;i<v;i++)
      {
        if(visited[i]==false)
        {
          if(util(i,visited,adj,-1))
               return true;
        }
      }
       return false;
	}
int main()
{
    int v=6;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
  	addEdge(adj, 1, 2);
  	addEdge(adj, 3, 4);
  	addEdge(adj, 4, 5);
   	addEdge(adj, 3, 5);
  	cout<<cycle_Exists(adj, v);
     return 0;
}
