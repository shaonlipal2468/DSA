#include<bits/stdc++.h>
using namespace std;
void print_array(vector<vector<int>> v,int row,int col)
{
   int i,j;
   for(i=0;i<row;i++)
   {
     for(j=0;j<col;j++)
      {
        cout<<v[i][j]<<"  ";
      }
     cout<<endl;
   }
   cout<<endl;
}
void prefixrowsum(vector<vector<int>> v,int row,int col,vector<vector<int>> &prefix_row)
{
   for(int i=0;i<row;i++)
       for(int j=1;j<col;j++)
          prefix_row[i][j] += prefix_row[i][j-1];
}
void prefixcolsum(vector<vector<int>> v,int row,int col,vector<vector<int>> &prefix_col)
{
   for(int i=1;i<row;i++)
       for(int j=0;j<col;j++)
           prefix_col[i][j]+= prefix_col[i-1][j];
}

void prefixrightdsum(vector<vector<int>> v,int row,int col,vector<vector<int>> &prefix_right_d)
{
   for(int i=1;i<row;i++)
       for(int j=0;j+1<col;j++)
              prefix_right_d[i][j]+=prefix_right_d[i-1][j+1];
}
void prefixleftdsum(vector<vector<int>> v,int row,int col,vector<vector<int>> &prefix_left_d)
{
   for(int i=1;i<row;i++)
       for(int j=1;j<col;j++)
              prefix_left_d[i][j]+= prefix_left_d[i-1][j-1];
}
bool inside(int row,int col,int i,int j)
{
  if(i<0||j<0||i>=row||j>=col)
     return false;
  return true;
}

bool four_same(int a,int b,int c,int d)
{
   if((a==b) && (b==c) && (c==d))
     return true;
   return false;
}

int check_row(bool &row_flag,vector<vector<int>> prefix_row,int top_x,int top_y,int bottom_x,int bottom_y,int size)
{
  //row sum check
  row_flag=true;
  int col_ = bottom_y;
  int sum =-1;
  if(top_y==0)
  {
    sum = prefix_row[top_x][col_];
    for(int i=top_x+1;i<top_x+size;i++)
    {
      if(prefix_row[i][col_]!=prefix_row[i-1][col_])
      {
          row_flag= false;
          break;
      }
    }
  }
  else
  {
    sum = prefix_row[top_x][col_]- prefix_row[top_x][col_-size];
    for(int i=top_x+1;i<top_x+size;i++)
    {
      if((prefix_row[i][col_]-prefix_row[i][col_-size])!=(prefix_row[i-1][col_]-prefix_row[i-1][col_-size]))
       {
         row_flag= false;
         break;
       }
    }
  }
  return sum;
}

int check_col(bool &col_flag,vector<vector<int>> prefix_col,int top_x,int top_y,int bottom_x,int bottom_y,int size)
{

  //col sum check
  col_flag = true;
  int row_ = bottom_x;
  int sum =-1;
  if(top_x == 0)
  {
    sum = prefix_col[row_][top_y];
    for(int i=top_y+1;i<top_y+size;i++)
    {
      if(prefix_col[row_][i]!=prefix_col[row_][i-1])
      {
          col_flag= false;
          break;
      }
    }
  }
  else
  {
    sum = prefix_col[row_][top_y]-prefix_col[row_-size][top_y];
    for(int i=top_y+1;i<top_y+size;i++)
    {
      if((prefix_col[row_][i]- prefix_col[row_-size][i] )!=(prefix_col[row_][i-1]- prefix_col[row_-size][i-1]))
       {
         col_flag = false;
         break;
       }
    }
  }
    return sum;
}
int check_left(vector<vector<int>> prefix_left_d,int top_x,int top_y,int bottom_x,int bottom_y,int size)
{
  if(top_x == 0 || top_y ==0)
    return prefix_left_d[bottom_x][bottom_y];
  return prefix_left_d[bottom_x][bottom_y] - prefix_left_d[bottom_x-size][bottom_y-size];
}

int check_right(vector<vector<int>> prefix_right_d,int top_x,int top_y,int bottom_x,int bottom_y,int size,int col)
{
    if(top_x == 0 || bottom_y == col-1)
       return prefix_right_d[bottom_x][top_y];
    return prefix_right_d[bottom_x][top_y]-prefix_right_d[bottom_x-size][top_y+size];
}

bool matrix_square_or_not(vector<vector<int>> v,vector<vector<int>> prefix_row,
          vector<vector<int>> prefix_col,vector<vector<int>> prefix_left_d,
          vector<vector<int>> prefix_right_d,int row,int col,int top_x,int top_y,int bottom_x,int bottom_y,int size)
{
  bool row_flag,col_flag;
  int row_situation = check_row(row_flag,prefix_row,top_x,top_y,bottom_x,bottom_y,size);
  int col_situation = check_col(col_flag,prefix_col,top_x,top_y,bottom_x,bottom_y,size);
  int left_d_sum = check_left(prefix_left_d,top_x,top_y,bottom_x,bottom_y,size);
  int right_d_sum = check_right(prefix_right_d,top_x,top_y,bottom_x,bottom_y,size,col);

  if(row_flag && col_flag && row_situation == col_situation)
     return four_same(row_situation ,col_situation,left_d_sum,right_d_sum);
  return false;
}

int solve(vector<vector<int>> v,vector<vector<int>> prefix_row,
          vector<vector<int>> prefix_col,vector<vector<int>> prefix_left_d,
          vector<vector<int>> prefix_right_d,int row,int col)
{
    int ans =1;
    for(int i=0;i<row;i++)
    {
      for(int j=0;j<col;j++)
      {
        int num = min(row,col);
        for(int k=2;k<=num;k++)
        {
            int top_x =i;
            int top_y=j;
            int bottom_x=i+k-1;
            int bottom_y = j+k-1;

            if(inside(row,col,bottom_x,bottom_y))
               {
                   if(matrix_square_or_not(v,prefix_row,prefix_col,
                                           prefix_left_d,prefix_right_d,row,col,
                                           top_x,top_y,bottom_x,bottom_y,k))
                        {
                          if(ans<k)
                              ans = k;
                        }
               }
        }
      }
    }
    return ans;
}
int main()
{
  vector<vector<int>> v {{7,1,4,5,6},{2,5,1,6,4},{1,5,4,3,2},{1,2,7,3,4}};
  //vector<vector<int>> v {{1,1,1,4},{4,6,9,2}};
  int row = v.size();
  int col = v[0].size();

  vector<vector<int>> prefix_row( row , vector<int> (col, 0));
  vector<vector<int>> prefix_col( row , vector<int> (col, 0));
  vector<vector<int>> prefix_left_d( row , vector<int> (col, 0));
  vector<vector<int>> prefix_right_d( row , vector<int> (col, 0));

  for(int i=0;i<row;i++)
     for(int j=0;j<col;j++)
        prefix_row[i][j]=prefix_col[i][j]=prefix_left_d[i][j]=prefix_right_d[i][j]=v[i][j];

  prefixrowsum(v,row,col,prefix_row);
  prefixcolsum(v,row,col,prefix_col);
  prefixleftdsum(v,row,col,prefix_left_d);
  prefixrightdsum(v,row,col,prefix_right_d);

  print_array(prefix_row,row,col);
  print_array(prefix_col,row,col);
  print_array(prefix_left_d,row,col);
  print_array(prefix_right_d,row,col);
  cout<<solve(v,prefix_row,prefix_col,prefix_left_d,prefix_right_d,row,col);
}
