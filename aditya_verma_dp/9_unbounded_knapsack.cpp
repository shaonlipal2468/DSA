#include<bits/stdc++.h>
using namespace std;

int knapsack_01(int weight[],int value[],int n,int w)
{
  int t[n+1][w+1],i,j;
  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<=w;j++)
    {
      if(i==0 || j==0 )
        t[i][j]=0;

      else if(weight[i-1]<=j)
         t[i][j]= max(value[i-1]+t[i][j-weight[i-1]],t[i-1][j]);

      else t[i][j] = t[i-1][j];
    }
  }
   return t[n][w];

 }


int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapsack_01(wt, val, n,W);
    return 0;
}
