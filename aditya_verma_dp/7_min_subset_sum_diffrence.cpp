#include<bits/stdc++.h>
using namespace std;
	int minDiffernce(int arr[],int n)
	{
		int sum=0,i,j;
 	  for(i=0;i<n;i++)
 			 sum +=arr[i];

	  int t[n+1][sum+1];
      for(i=0;i<=sum;i++)
         t[0][i] = false;

      for(i=0;i<=n;i++)
         t[i][0] = true;

      for(i=1;i<=n;i++)
      {
        for(j=1;j<=sum;j++)
        {
          if(arr[i-1]>j)
             t[i][j] = t[i-1][j];
          else t[i][j]= t[i-1][j] || t[i-1][j-arr[i-1]];
        }
      }
			int mn=INT_MAX;
			for(i=0;i<=sum/2;i++)
			{
				  if(t[n][i]==true)
						mn=min(mn,sum-2*i);
			}
     return mn;
	}
int main()
{
	int arr[] = {1, 6,5,11} ;
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<minDiffernce(arr,n);

}
