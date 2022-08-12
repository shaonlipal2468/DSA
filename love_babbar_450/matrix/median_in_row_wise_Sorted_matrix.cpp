#include<bits/stdc++.h>
using namespace std;

int counter(vector<vector<int>> v,int mid)
{
  int row = v.size();
  int col = v[0].size();
  int count=0;

  for(int i=0;i<row;i++)
  {
      for(int j=col-1;j>=0;j--)
      {
          if(v[i][j]<=mid)
          {
              count+=j+1;
              break;
          }
      }
  }
  return count;
}
int binaryMedian(vector<vector<int>> v)
{

  int row = v.size();
  int col = v[0].size();

  int desired = (row*col+1)/2;
  int low = INT_MAX;
  int high = INT_MIN;
  //find minimum
  for(int i=0;i<row;i++)
      low= min(low,v[i][0]);
  //find maximum
  for(int i=0;i<row;i++)
      high= max(high,v[i][col-1]);

  int mid = low+(high-low)/2;

  while(low<high)
  {
    int mid = low+(high-low)/2;
    int count= counter(v,mid);
    if(count>=desired)
        high=mid;
    else
        low=mid+1;
  }
  return low;
}
int main()
{
    vector<vector<int>> v { {1,3,5}, {2,6,9}, {3,6,9} };
    cout << "Median is " << binaryMedian(v) << endl;
    return 0;
}
