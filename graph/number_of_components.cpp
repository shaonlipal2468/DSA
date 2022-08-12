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
void util(int src,vector<bool> &visited,vector<int> adj[],vector<int> &component)
    {
        visited[src]=true;
        component.push_back(src);
        for(auto neighbour: adj[src])
        {
          if(!visited[neighbour])
            util(neighbour,visited,adj,component);
        }        
    }
	//Function to return a list containing the DFS traversal of the graph.
int number_of_Components(vector<int> adj[],int v)
	{
      int count =0;
      vector<int> component;
	    vector<bool> visited(v,false);
	    for(int i=0;i<v;i++)
      {
          if(visited[i]==false)
          {
            count++;
            util(i,visited,adj,component);
            print_arr(component);
            component.clear();
          }
     }
      return count;

	}
int main()
{
    int v=7;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
  	addEdge(adj, 2, 3);
  	addEdge(adj, 4, 5);
  	addEdge(adj, 5, 6);
  	addEdge(adj, 4, 6);
  	cout<<number_of_Components(adj, v);

     return 0;
}
