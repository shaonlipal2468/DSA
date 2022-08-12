#include<bits/stdc++.h>
using namespace std;

void print_vector(vector<int> arr)
{
  for(int i=0;i<arr.size();i++)
     cout<<arr[i]<<" ";
  cout<<endl;
}

vector<int> spirallyTraverse(vector<vector<int> > arr, int row, int col)
{
    // code here
int min_col = 0;
int min_row = 0;
vector<int> ans;

int max_col = col-1;
int max_row = row-1;
int total_elements = row*col;
int count =0;

//int *ans = (int *)malloc(total_elements*sizeof(int));

while(count<total_elements)
{
 //top wall (min row is fixed, col : min col to max col)
 for(int i=min_row,j=min_col;j<=max_col && count<total_elements;j++)
      {
       ans.push_back(arr[i][j]);
       count++;
      }
 min_row++;


 //right wall(max col is fixed , row : min row to max row)
 for(int i=min_row,j=max_col;i<=max_row && count<total_elements;i++)
        {
         ans.push_back(arr[i][j]);
          count++;
        }

 max_col--;

 //bottom wall(max row is fixed. col : max col to min col)
 for(int i=max_row,j=max_col;j>=min_col && count<total_elements;j--)
     {
      ans.push_back(arr[i][j]);
       count++;
     }

 max_row--;

 //left wall(min col is fixed, row :max row to min row)
 for(int i=max_row,j=min_col;i>=min_row && count<total_elements;i--)
    {
      ans.push_back(arr[i][j]);
       count++;
    }

 min_col++;

}
return ans;

}


int main()
{
  /*int matrix[][4]={{1,2,3,4},
                    {5,6,7,8},
                    {9,10,11,12},
                    {13,14,15,16}

                  };
int row=4;
int col=4;

  */
  vector<vector<int> > arr {{5,11},{30,5},{19,19}};
  int row=3;
  int col=2;

  vector<int> ans = spirallyTraverse(arr,row,col);
  print_vector(ans);
}
