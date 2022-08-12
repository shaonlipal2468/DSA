#include<iostream>
using namespace std;
class Solution
{
  public:

    long long int count(int coins[], int n, int sum )
    {
        long long int t[n+1][sum+1],i,j;
        for(i=0;i<=sum;i++)
           t[0][i]=0;
        for(i=0;i<=n;i++)
           t[i][0]=1;

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=sum;j++)
            {
                if(coins[i-1]>j)
                    t[i][j] = t[i-1][j];
                else
                  t[i][j]= t[i-1][j] +t[i][j-coins[i-1]];
            }
        }
        return t[n][sum];

    }

};


int main()
{
    int t;
    cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[m];
		for(int i=0;i<m;i++)
		    cin>>arr[i];
	    Solution ob;
		cout<<ob.count(arr,m,n)<<endl;
	}


    return 0;
} 
