/*
Write an efficient algorithm that searches for a value in an m x n matrix.
This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 */
#include<bits/stdc++.h>
using namespace std;
int binary_search(vector<int> arr,int start,int end,int search)
    {
        while(start<=end)
        {
            int middle = start+ (end-start)/2;
            if(arr[middle] == search)
                 return middle;
            else if(arr[middle]>search)
               end = middle-1;
            else
               start=middle+1;
    }
	return -1;
    }
    bool searchMatrix(vector<vector<int>> matrix, int target) {
        int row= matrix.size();
        int col= matrix[0].size();
        int start_index,end_index;
        int flag = 0;
        for(int i=0;i<row;i++)
        {

            if(matrix[i][0]<= target && target <= matrix[i][col-1])
            {
                if(binary_search(matrix[i],0,col-1,target)>=0)
                {
                  flag=1;
                  break;
                }
            }
        }
        return flag;
    }
    int main()
    {
      vector<vector<int> > arr {{1,3,5,7},
                                {10,11,16,20},
                                {23,30,34,60}};
      int search =13;
      cout<<searchMatrix(arr,search)<<endl;
    }
