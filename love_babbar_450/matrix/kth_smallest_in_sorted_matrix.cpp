#include<bits/stdc++.h>
using namespace std;
int counter(vector<vector<int>>& matrix,int mid)
    {
        int row= matrix.size();
        int col = matrix[0].size();
        int count=0;

        for(int i=0;i<row;i++)
        {
            for(int j=col-1;j>=0;j--)
            {
                if(matrix[i][j]<=mid)
                {
                    count+=j+1;
                    break;
                }
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row= matrix.size();
        int col = matrix[0].size();

        int low=matrix[0][0];
        int high=matrix[row-1][col-1];

        int count;

        while(low<high)
        {
            int mid = low+(high-low)/2;
            count= counter(matrix,mid);
            if(count>=k)
                high=mid;
            else
                low=mid+1;

        }
        return low;

    }
    int main()
{
    vector<vector<int>> mat {
        { 10, 20, 30, 40 },
        { 15, 25, 35, 45 },
        { 25, 29, 37, 48 },
        { 32, 33, 39, 50 },
    };
    int k=7;
    cout << "7th smallest element is "
         << kthSmallest(mat,  7)<<endl;
    return 0;
}
