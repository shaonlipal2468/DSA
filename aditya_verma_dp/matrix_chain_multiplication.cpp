#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
int t[101][101];

class Solution{
public:
int matrixutil(int arr[],int i,int j)
{
    if(i>=j)
      return 0;
    if(t[i][j]!=-1)
       return t[i][j];
    int mn=INT_MAX;

    for(int k=i;k<j;k++)
    {
        int temp_ans= matrixutil(arr,i,k)
                      +matrixutil(arr,k+1,j)
                      +arr[i-1]*arr[j]*arr[k];
        if(temp_ans<mn)
           mn=temp_ans;
    }
    return t[i][j]=mn;

}
    int matrixMultiplication(int n, int arr[])
    {
        // code here
        memset(t,-1,sizeof(t));
        int i=1;
        int j=n-1;
        return matrixutil(arr,i,j);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends
