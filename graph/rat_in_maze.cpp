#include<bits/stdc++.h>
using namespace std;
void print_arr(vector<string> arr)
{
  for(auto s: arr)
     cout<<s<<" ";
  cout<<endl;
}
void dfs(int i ,int j, string path,vector<string> &paths,vector<vector<int>> &matrix,vector<vector<int>> &visited,int n)
{
   if(i<0 || i>=n || j<0 || j>=n || !matrix[i][j] || visited[i][j])
      return;
   if(i== n-1 && j==n-1)
   {
      paths.push_back(path);
      return;
   }
   visited[i][j]=1;
   dfs(i-1,j,path+'U',paths,matrix,visited,n);
   dfs(i+1,j,path+'D',paths,matrix,visited,n);
   dfs(i,j-1,path+'L',paths,matrix,visited,n);
   dfs(i,j+1,path+'R',paths,matrix,visited,n);
   visited[i][j]=0;
}
vector<string> printPaths(int n,vector<vector<int>> &matrix)
{
  vector<string> paths;
  vector<vector<int>> visited( n , vector<int> (n, 0));
  if(matrix[0][0]==0 || matrix[n-1][n-1]==0)
        return paths;
  string path ="";
  dfs(0,0,path,paths,matrix,visited,n);
  sort(paths.begin(),paths.end());
  return paths;
}


int main()
{
    int n= 5;
    vector<vector<int>> matrix{ { 1, 0, 0, 0, 0 },
                              { 1, 1, 1, 1, 1 },
                              { 1, 1, 1, 0, 1 },
                              { 0, 0, 0, 0, 1 },
                              { 0, 0, 0, 0, 1 } };
    vector<string> paths = printPaths(n,matrix);
    print_arr(paths);

}
