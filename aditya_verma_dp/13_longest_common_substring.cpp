#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:

    int longestCommonSubstr (string s1, string s2, int x, int y)
    {
        // your code here
        int t[x+1][y+1],i,j;
        int result=0;
        for(i=0;i<=x;i++)
        {
            for(j=0;j<=y;j++)
            {
                if(i==0 || j==0)
                     t[i][j]=0;
                else if(s1[i-1] == s2[j-1])
                {
                   t[i][j]= 1+t[i-1][j-1];
                   result=max(result,t[i][j]);
                }
                else
                   t[i][j]= 0;
             }
        }
        return result;
        }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
