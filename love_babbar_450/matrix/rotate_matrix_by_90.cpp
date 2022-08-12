//Not inplace solution
#include<bits/stdc++.h>
#define N 3
using namespace std;
void printMatrix(int arr[N][N])
{
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<N;j++)
    {
      cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
}
void transpose(int arr[N][N],int ans[N][N])
{
  for(int i=0;i<N;i++)
     for(int j=0;j<N;j++)
        ans[i][j]=arr[j][i];
}

void reverse(int arr[N][N],int ans[N][N])
{
  for(int i=0;i<N;i++)
     for(int j=0;j<N;j++)
        ans[i][j]=arr[i][N-j-1];
}

void rotate90Clockwise(int arr[N][N],int trans[N][N],int rev[N][N])
{
  transpose(arr,trans);
  reverse(trans,rev);
}

int main()
{
  int arr[N][N] =  { { 1, 2, 3 },
                    { 4, 5, 6 },
                    { 7, 8, 9 } };
    int trans[N][N],rev[N][N];

    rotate90Clockwise(arr,trans,rev);
    printMatrix(rev);
}
