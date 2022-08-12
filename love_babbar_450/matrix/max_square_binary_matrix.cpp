#include<bits/stdc++.h>
using namespace std;

int min_of_three(int n1,int n2,int n3)
{
  return n1 < n2 ? (n1 < n3 ? n1 : n3) : (n2  <n3 ? n2 : n3);
}

int max_size_square(int arr[5][6],int row,int col)
{
  int i,j;
  int ans = INT_MIN;
  int dp[row][col];
  for(i=row-1;i>=0;i--)
  {
      for(j=col-1;j>=0;j--)
        {
            if(i==row-1 || j==col-1)
                 {
                  dp[i][j]=arr[i][j];
                  ans=max(ans,dp[i][j]);
                 }
            else
                {
                   if(arr[i][j]==1)
                       {
                        dp[i][j] = 1 + min_of_three(dp[i+1][j],dp[i][j+1],dp[i+1][j+1]);
                        ans=max(ans,dp[i][j]);
                      }
                   else
                       {
                        dp[i][j]=0;
                        ans=max(ans,dp[i][j]);
                      }
                }
        }
  }

  return ans;
}

int main()
{
  int arr[][6]={{0,1,0,1,0,1},
                {1,0,1,0,1,0},
                {0,1,1,1,1,0},
                {0,0,1,1,1,0},
                {1,1,1,1,1,1}};
  int row = 5;
  int col =6;

  cout<<max_size_square(arr,row,col);
}
