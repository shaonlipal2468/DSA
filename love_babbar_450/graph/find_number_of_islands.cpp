#include<bits/stdc++.h>
using namespace std;

void mark_current_island(vector<vector<char>> &grid,
                         int i,int j,int rows,int cols)
{
    if(i<0 || i>=rows || j<0 || j>=cols || grid[i][j]!='1')
       return;
    //mark it as visited
    grid[i][j]='2';
    mark_current_island(grid,i-1,j-1,rows,cols);
    mark_current_island(grid,i-1,j,rows,cols);
    mark_current_island(grid,i-1,j+1,rows,cols);
    mark_current_island(grid,i,j-1,rows,cols);
    mark_current_island(grid,i,j+1,rows,cols);
    mark_current_island(grid,i+1,j-1,rows,cols);
    mark_current_island(grid,i+1,j,rows,cols);
    mark_current_island(grid,i+1,j+1,rows,cols);

}
//Function to find the number of islands.
int numIslands(vector<vector<char>>& grid)
{
    // Code here
    int rows= grid.size();
    int cols = grid[0].size();
    if(rows==0)
       return 0;

    int count =0;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(grid[i][j]=='1')
            {
                mark_current_island(grid,i,j,rows,cols);
                count++;
            }
        }
    }
    return count;
}
//o means water 1 means land 2 means visited
//Leetcode 200 same problem - only difference is diagonally will not go
int main()
{
  vector<vector<char>> grid = {{'0','1'},{'1','0'},{'1','1'},{'1','0'}};
  cout<<numIslands(grid);
}
