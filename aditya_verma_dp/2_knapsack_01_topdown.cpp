#include<bits/stdc++.h>
using namespace std;

int knapsack_01(int weight[],int value[],int n,int w)
{

  int t[n+1][w+1];
  memset(t,-1,sizeof(t));

  if(n==0 || w==0)
       return 0;

  if(t[n][w]!=-1)
     return t[n][w];

  else if(weight[n-1]>w)
    return t[n][w]= knapsack_01(weight,value,n-1,w);

  else   // if(weight[n-1]<=w)
    return t[n][w]=max(value[n-1]+knapsack_01(weight,value,n-1,w-weight[n-1]),
               knapsack_01(weight,value,n-1,w));
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
