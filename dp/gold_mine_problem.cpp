#include<bits/stdc++.h>
using namespace std;
const int MAX = 100;


int getMaxGold(int gold[][MAX],int m,int n)
{
  int table[m][n];
  //initialization with 0
  memset(table,0,sizeof(table));
  int row,col;

  for(col=n-1;col>=0;col--)
  {
    for(row=m-1;row>=0;row--)
    {
      int right = (col==n-1)?0: table[row][col+1];
      int right_up = (col==n-1 || row==0 )? 0 :table[row-1][col+1];
      int right_down = (col==n-1 || row==m-1)?0:table[row+1][col+1];

      table[row][col] =gold[row][col] + max(right,max(right_up,right_down));
    }
  }
  int ans=table[0][0];
  for(int i=0;i<m;i++)
    {
       if(ans<table[i][0])
           ans=table[i][0];
    }

    for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
      {
        cout<<table[i][j]<<" ";
      }
      cout<<endl;
    }
    cout<<endl;
    return ans;
}
int main()
{
  int gold[MAX][MAX]= { {1, 3, 1, 5},
        {2, 2, 4, 1},
        {5, 0, 2, 3},
        {0, 6, 1, 2}
    };
    int m = 4, n = 4;
    cout << getMaxGold(gold, m, n);
    return 0;
}
