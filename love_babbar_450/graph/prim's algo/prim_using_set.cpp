//https://www.youtube.com/watch?v=NR4fpjuxnPA
#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int,int>> adj[],int u,int v,int weight)
{
   adj[u].push_back({v,weight});
   adj[v].push_back({u,weight});
}
//
// void print_Adj(vector<pair<int,int>> adj[],int v)
// {
//   for(int i=0;i<v;i++)
//   {
//       for(auto x : adj[i])
//       {
//         cout<<i<<" "<<x.first<<" "<<x.second<<endl;
//       }
//       cout<<endl;
//   }
// }

void printArr(vector<int> parent, int n)
{
    for (int i = 1; i < n; ++i)
        cout<<parent[i]<<" - "<<i<<endl;
    cout<<endl;
}
//let say source node is 0
void prim_using_set(vector<pair<int,int>> adj[],int v)
{
    //make a set to find out mode with minimum curr_distance
    //By default set sort according to the first parameter
    set<pair<int,int>> s;    //set : {distance,node}
    vector<int> distance(v,INT_MAX);
    vector<bool> inMST(v, false);
    vector<int> parent(v,-1);

    int source=0;

    //Initialization
    distance[source]=0; //distance of source is 0
    s.insert({0,source});

    while(!s.empty())
    {
      //get the minimum by popping at front
      auto p =*(s.begin());
      int u = p.second;
      s.erase(s.begin());

      if(inMST[u] == true)
           continue;
      inMST[u]=true;

      //iterate over neighbors of current node and relax edges
      for(auto edge : adj[u])
      {
        int v= edge.first;
        int weight = edge.second;
        if(inMST[v] == false && weight < distance[v])
        {
             //In a set,updation is not possible we have to remove the old pair and insert the new pair
             //finding old pair
             auto find_old = s.find({distance[v],v});
             if(find_old!=s.end())
                   s.erase(find_old);
             //insert the new pair
             distance[v]= weight;
             s.insert({distance[v],v});
             parent[v]= u;
        }
      }
   }
      printArr(parent,v);
}

int main()
{
  int v=6;
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
  //print_Adj(adj,v);
  prim_using_set(adj,v);


}
