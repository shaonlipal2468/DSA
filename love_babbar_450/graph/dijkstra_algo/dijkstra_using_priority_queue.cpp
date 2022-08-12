//https://www.youtube.com/watch?v=msU3onT4CbY&list=PL2q4fbVm1Ik64I3VqbVGRfl_OgYzvzt9m&index=8
#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int,int>> adj[],int u,int v,int weight)
{
   adj[u].push_back({v,weight});
   adj[v].push_back({u,weight});
}

void print_Adj(vector<pair<int,int>> adj[],int v)
{
  for(int i=0;i<v;i++)
  {
      for(auto x : adj[i])
      {
        cout<<i<<" "<<x.first<<" "<<x.second<<endl;
      }
      cout<<endl;
  }
}

void printArr(vector<int> parent, int n)
{
    for (int i = 1; i < n; ++i)
        cout<<parent[i]<<" - "<<i<<endl;
    cout<<endl;
}
//let say source node is 0
void dijkstra(vector<pair<int,int>> adj[],int v)
{
    //min heap
    int source =0;
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> distance(v,INT_MAX);
    vector<int> parent(v,-1);
    pq.push({0,source});  //0th node source , distance 0 (distance,node)
    distance[source]=0;

    while(!pq.empty())    //priority queue : {distance,node}
    {
       int u = pq.top().second;
       pq.pop();

       //relax all adjacent nodes distance
       for(auto edge : adj[u])
       {
          int v= edge.first;
          int weight = edge.second;
         if(distance[u]+weight < distance[v])
         {
             distance[v] = distance[u]+weight ;
             pq.push({distance[v],v});
             parent[v]= u;
         }
       }
    }

    for(int i=0;i<v;i++)
      cout<<i<<" " <<distance[i]<<endl;
    cout<<endl;

    printArr(parent,v);
}

int main()
{
  int v=6; //nodes will be 0 to 5
  vector<pair<int,int>> adj[v];
  addEdge(adj,0,1,4);
  addEdge(adj,0,5,2);
  addEdge(adj,1,2,5);
  addEdge(adj,1,5,1);
  addEdge(adj,2,3,6);
  addEdge(adj,2,4,3);
  addEdge(adj,3,4,5);
  addEdge(adj,4,5,10);
  addEdge(adj,2,5,8);
  print_Adj(adj,v);
  dijkstra(adj,v);


}
