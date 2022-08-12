#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
bool util(vector<int> adj[],vector<bool> &visited,int src,int v)
    {
        visited[src]= true;
        vector<int> parent(v,-1);
        queue<int> q;
        q.push(src);
        while(!q.empty())
        {
            int temp = q.front();
            q.pop();
            for(auto neighbour: adj[temp])
            {
                if(!visited[neighbour])
                {
                    visited[neighbour]= true;
                    q.push(neighbour);
                    parent[neighbour] = temp;
                }
                else if(parent[temp]!=neighbour)
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
        if(!visited[i])
        {
             if(util(adj,visited,i,v))
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
