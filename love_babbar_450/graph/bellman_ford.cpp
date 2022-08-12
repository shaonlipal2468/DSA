#include<bits/stdc++.h>
using namespace std;
void addEdge( vector<vector<int> > &edges,int u,int v,int w)
{
		edges.push_back({u,v,w});
}
int isNegativeWeightCycle(int n, vector<vector<int>> &edges){
		// Code here
		vector<int> distance(n,INT_MAX);
		distance[0]=0;
		for(int i=1;i<=n-1;i++)
		{
				for (auto edge: edges)
				{
						int u=edge[0];
						int v=edge[1];
						int weight= edge[2];
						if(distance[u] != INT_MAX && distance[u]+weight<distance[v])
									distance[v]=distance[u]+weight;
				}
		}
		for (auto edge: edges)
				{
						int u=edge[0];
						int v=edge[1];
						int weight= edge[2];

						if(distance[u] != INT_MAX && distance[u]+weight<distance[v])
									return 1;
				}
				return 0;
}

	int main(){
    int n,m;
		 vector<vector<int> > edges;/*
    n=3,m=3;
		addEdge(edges,0,1,-1);
		addEdge(edges,1,2,-2);
		addEdge(edges,2,0,-3);

		*/
		n=7,m=25;

		addEdge(edges,0,1,2);
		addEdge(edges,0,2,-2);
		addEdge(edges,0,3,-1);
		addEdge(edges,0,4,-6);
		addEdge(edges,0,6,2);
		addEdge(edges,1,0,-2);
		addEdge(edges,1,2,4);
		addEdge(edges,1,4,-7);
		addEdge(edges,1,6,10);
		addEdge(edges,2,0,-8);
		addEdge(edges,2,1,10);
		addEdge(edges,2,6,-8);
		addEdge(edges,3,1,-1);
		addEdge(edges,3,4,4);
		addEdge(edges,4,1,-11);
		addEdge(edges,4,2,-10);
		addEdge(edges,4,3,-4);
		addEdge(edges,5,0,1);
		addEdge(edges,5,2,8);
		addEdge(edges,5,3,-3);
		addEdge(edges,5,4,3);
		addEdge(edges,5,6,6);
		addEdge(edges,6,0,9);
		addEdge(edges,6,1,1);
		addEdge(edges,6,3,-11);


		int ans = isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";


	}
