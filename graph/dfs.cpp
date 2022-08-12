#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void print_arr(vector<int> arr)
{
  for(auto x: arr)
    cout<<x<<" ";
  cout<<endl;
}
void util(int src,vector<bool> &visited,vector<int> adj[],vector<int> &dfs)
    {
        visited[src]=true;
        dfs.push_back(src);
        for(auto neighbour: adj[src])
            if(!visited[neighbour])
              util(neighbour,visited,adj,dfs);

    }
	//Function to return a list containing the DFS traversal of the graph.
void DFS(vector<int> adj[],int v)
	{
      vector<int> dfs;
	    vector<bool> visited(v,false);
	    for(int i=0;i<v;i++)
          if(visited[i]==false)
              util(i,visited,adj,dfs);
      print_arr(dfs);
	}
int main()
{
    int v=5;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
  	addEdge(adj, 0, 4);
  	addEdge(adj, 1, 2);
  	addEdge(adj, 1, 3);
  	addEdge(adj, 1, 4);
  	addEdge(adj, 2, 3);
  	addEdge(adj, 3, 4);
  	DFS(adj, v);

     return 0;
}
