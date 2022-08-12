/*
Given an integer N denoting the Length of a line segment.
 You need to cut the line segment in such a way that
 the cut length of a line segment each time is either x , y or z.
  Here x, y, and z are integers.
After performing all the cut operations,
your total number of cut segments must be maximum
*/

#include<bits/stdc++.h>
using namespace std;

int maximizeTheCuts(int n, int x, int y, int z);

int main() {

    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;

        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;

        //calling function maximizeTheCuts()
        cout<<maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}// } Driver Code Ends


//Complete this function
int maximizeTheCuts(int sum, int x, int y, int z)
{
    //Your code here
    int segments[]={x,y,z};
   int n=3;

    int t[n+1][sum+1],i,j;
      for(i=0;i<=sum;i++)
         t[0][i]=INT_MIN;
      for(i=1;i<=n;i++)
         t[i][0]=0;

     for(j=1;j<=sum;j++)
     {
         if(j%segments[0]==0)
              t[1][j]= j/segments[0];
         else t[1][j]= INT_MIN;
     }
     for(i=2;i<=n;i++)
        {
            for(j=1;j<=sum;j++)
            {
                if(segments[i-1]>j)
                   t[i][j]= t[i-1][j];
                 else
                    t[i][j] = max(1+t[i][j-segments[i-1]],t[i-1][j]);
            }
        }

        if(t[n][sum] < -2147400000)
        return 0; //not possible
        else return t[n][sum];
}
