#include<bits/stdc++.h>
using namespace std;
#define v 6
int selectMinVertex(vector<int> &distance,vector<bool> &setMST)
{
  int minimum=INT_MAX;
  int vertex;
  for(int i=0;i<v;i++)
  {
    if(setMST[i]==false && distance[i]<minimum)
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
    vector<bool> setMST(v,false);

    //initialization
    distance[0]=0;

    for(int i=0;i<v-1;i++)
    {
        //select best vertex by greedy method
        int u = selectMinVertex(distance,setMST);
        setMST[u]= true;

        //relax unsetMST adjacent nodes
        for(int j=0;j<v;j++)
        {
          /* 3 constraints to relax
             a) edge is present from u to j
             b) vertex j is not included yet
             c) updated weight is less than the old weight
          */
            if(graph[u][j] && setMST[j]==false && graph[u][j]<distance[j])
            {
                distance[j]= graph[u][j];
                parent[j]=u;
            }
        }

    }
    // for(int i=0;i<v;i++)
    //    cout<<parent[i]<<" ";
    // cout<<endl;
    //
    // for(int i=0;i<v;i++)
    //    cout<<distance[i]<<" ";
    // cout<<endl;

    for(int i=1;i<v;i++)
    {
      cout<<parent[i]<<"->"<<i<<"   weight "<< graph[parent[i]][i]<<endl;
    }
}

int main()
{

   int graph[v][v]={{0,1,4,0,0,0},
                    {1,0,4,2,7,0},
                    {4,4,0,3,5,0},
                    {0,2,3,0,4,6},
                    {0,7,5,4,0,7},
                    {0,0,0,6,7,0}} ;

    dijkstra(graph);

}
