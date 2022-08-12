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
void util(vector<int> adj[],vector<int> &bfs,vector<bool> &visited,int src)
{
    queue<int> q;
    q.push(src);
    visited[src]=true;
    while(q.empty()!=1)
    {
        int temp = q.front();
        q.pop();
        bfs.push_back(temp);

        for(auto neighbour: adj[u])
        {
          if(!visited[neighbour])
          {
            visited[neighbour]=true;
            q.push(neighbour);
          }
        }
    }
}
void BFS(vector<int> adj[],int v)
{
    vector<int> bfs ;   //ans will be written in this
    vector<bool> visited(v,false);
    for(int i=0;i<v;i++)
        if(!visited[i])
           util(adj,bfs,visited,i);
    print_arr(bfs);
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
  	BFS(adj, v);
     return 0;
}
