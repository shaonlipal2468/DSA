#include<bits/stdc++.h>

using namespace std;

int count(int arr[],int n)
{
    int dp[n+1];
    dp[n]=0;

    for(int i=n-1;i>=0;i--)
    {
        if(arr[i]==0)
          dp[i]=INT_MAX;
        else
        {
            int temp=INT_MAX;
            for(int j=1;j<=arr[i] && i+j<=n;j++)
            {
                temp=min(temp,dp[i+j]);
            }
            if(temp!=INT_MAX)
               dp[i]=temp+1;
            else
               dp[i]=INT_MAX;

        }

    }
    return dp[0];
}

int main()
{
   int n=10;
   int arr[n]= {3,2,4,2,0,2,3,1,2,2};
   cout<<count(arr,n)<<endl;

   return 0;
}
