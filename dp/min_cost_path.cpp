// A Naive recursive implementation
// of MCP(Minimum Cost Path) problem
#include <bits/stdc++.h>
using namespace std;

#define R 3
#define C 3
// Returns cost of minimum cost path
// from (0,0) to (m, n) in mat[R][C]
int minCost(int cost[R][C], int m, int n)
{
	if (n < 0 || m < 0)
	 	return INT_MAX;
 else if (m == 0 && n == 0)
		return cost[m][n];
	else
		return cost[m][n] +
		min(minCost(cost, m - 1, n - 1),
			min(minCost(cost, m - 1, n),
			minCost(cost, m, n - 1)));
}

int bottom_up(int cost[R][C], int m, int n)
{
  int table[R][C];
  table[0][0]=cost[0][0];
  //intialize first row
  for(int i=1;i<=n;i++)
    table[0][i] = table[0][i-1] + cost[0][i];

    //intialize first column
    for(int i=1;i<=m;i++)
      table[i][0] = table[i-1][0] + cost[i][0];

    //fill up rest cells
    for(int i=1;i<=m;i++)
    {
      for(int j=1;j<=n;j++)
      {
        table[i][j] = cost[i][j] + min(table[i-1][j-1],min(table[i][j-1],table[i-1][j]));
      }
    }
   return table[m][n];
}


// Driver code
int main()
{
	int cost[R][C] = { { 1, 2, 3 },
					{ 4, 8, 2 },
					{ 1, 5, 3 } };

	cout << minCost(cost,2,2) << endl;
  cout<< bottom_up(cost,2,2)<<endl;

	return 0;
}
