// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int shortestCommonSupersequence(char* , char*, int, int );

int main()
{

    int t;
    char X[10001], Y[10001];

    //taking total testcases
    cin >> t;
    while(t--){

    //taking String X and Y
	cin >> X >> Y;

	//calling function shortestCommonSupersequence()
	cout << shortestCommonSupersequence(X, Y, strlen(X), strlen(Y))<< endl;
    }
	return 0;
}

// } Driver Code Ends


//User function template for C++

// X : 1st given string of size m
// Y : 2nd given string of size n
int shortestCommonSupersequence(char* X, char* Y, int m, int n) {
    //code here

    int t[m+1][n+1],i,j;
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0||j==0)
              t[i][j]=0;
            else if(X[i-1]==Y[j-1])
              t[i][j]=1+t[i-1][j-1];
            else
               t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
    }

    return m+n-t[m][n];

}
