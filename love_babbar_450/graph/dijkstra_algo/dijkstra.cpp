#include<bits/stdc++.h>
using namespace std;
#define v 6
int selectMinVertex(vector<int> &distance,vector<bool> &visited)
{
  int minimum=INT_MAX;
  int vertex;
  for(int i=0;i<v;i++)
  {
    if(visited[i]==false && distance[i]<minimum)
      {
         minimum=distance[i];
         vertex=i;
      }
  }
  return vertex;
}

//let say source is 0 node
void dijkstra(int graph[v][v])
{
    vector<int> parent(v,-1);
    vector<int> distance(v,INT_MAX);
    vector<bool> visited(v,false);

    //initialization
    distance[0]=0;

    for(int i=0;i<v-1;i++)
    {
        //select best vertex by greedy method
        int u = selectMinVertex(distance,visited);
        visited[u]= true;

        //relax unvisited adjacent nodes
        for(int j=0;j<v;j++)
        {
          /* 3 constraints to relax
             a) edge is present from u to j
             b) vertex j is not included yet
             c) updated weight is less than the old weight
          */
            if(graph[u][j] && visited[j]==false && distance[u]!=INT_MAX
            && distance[u]+graph[u][j]<distance[j])
            {
                distance[j]= distance[u]+graph[u][j];
                parent[j]=u;
            }
        }

    }
    cout<<"Node : Distance from source 0 "<<endl;
     for(int i=1;i<v;i++)
        cout<<i<< "        " <<distance[i]<<endl;
     cout<<endl;

    cout<<"The graph is "<<endl;
    for(int i=1;i<v;i++)
    {
      cout<<parent[i]<<"->"<<i<<"   weight "<< graph[parent[i]][i]<<endl;
    }
}

int main()
{
   /*
   int graph[v][v]={{0,1,4,0,0,0},
                    {1,0,4,2,7,0},
                    {4,4,0,3,5,0},
                    {0,2,3,0,4,6},
                    {0,7,5,4,0,7},
                    {0,0,0,6,7,0}} ;

    */
    int graph[v][v]={{0,4,0,0,0,2},
                     {4,0,5,0,0,1},
                     {0,5,0,6,3,8},
                     {0,0,6,0,5,0},
                     {0,0,3,5,0,10},
                     {2,1,8,0,10,0}} ;

    dijkstra(graph);

}
