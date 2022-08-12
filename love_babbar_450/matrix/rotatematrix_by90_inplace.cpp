//inplace solution
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
void transpose(int arr[N][N])
{
  for(int i=0;i<N;i++)
     for(int j=i;j<N;j++)
        swap(arr[i][j],arr[j][i]);
}

void reverse(int arr[N][N])
{
  for(int i=0;i<N;i++)
     {
       int low_index=0;
       int high_index=N-1;
       while(low_index<high_index)
       {
         swap(arr[i][low_index],arr[i][high_index]);
         low_index++;
         high_index--;
       }
     }
}

void rotate90Clockwise(int arr[N][N])
{
  transpose(arr);
  reverse(arr);
}

int main()
{
  int arr[N][N] =  { { 1, 2, 3 },
                    { 4, 5, 6 },
                    { 7, 8, 9 } };


    rotate90Clockwise(arr);
    printMatrix(arr);
}
