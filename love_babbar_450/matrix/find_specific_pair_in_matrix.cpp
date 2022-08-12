//https://www.codingninjas.com/codestudio/problem-details/find-a-specific-pair-in-the-matrix_1115467

#include<bits/stdc++.h>
#define N 5
using namespace std;

int min_of_three(int n1,int n2,int n3)
{
  return n1<n2?(n1<n3?n1:n3):(n2<n3?n2:n3);
}
int findMaxValue(int matrix[N][N],int row,int col)
{
  int dp[row][col];
  int maxValue = INT_MIN;
  dp[0][0]=matrix[0][0];

  for(int i=0;i<row;i++)
      dp[i][0]=min(matrix[i][0],dp[i-1][0]);

  for(int j=0;j<col;j++)
      dp[0][j]=min(matrix[0][j],dp[0][j-1]);

  for(int i=1;i<row;i++)
  {
    for(int j=1;j<col;j++)
    {
      maxValue = max(maxValue, matrix[i][j]-dp[i-1][j-1]);
      dp[i][j]= min_of_three(dp[i-1][j],dp[i][j-1],matrix[i][j]);
    }
  }
  return maxValue;

}
int main()
{
   int matrix[N][N]={{ 1, 2, -1, -4, -20 },
                      { -8, -3, 4, 2, 1 },
                      { 3, 8, 6, 1, 3 },
                      { -4, -1, 1, 7, -6 },
                      { 0, -4, 10, -5, 1 }};
   int row=N;
   int col=N;
   cout<<findMaxValue(matrix,row,col);
}
