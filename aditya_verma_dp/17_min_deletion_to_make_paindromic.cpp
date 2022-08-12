#include <bits/stdc++.h>
using namespace std;
int minimumNumberOfDeletions(string str);

int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        cout << minimumNumberOfDeletions(S) << endl;
    }
return 0;
}// } Driver Code Ends




int minimumNumberOfDeletions(string a) {
    // code here
    string b;
    b=a;
    //strcpy(b,a);
    reverse(b.begin(), b.end());

    int m=a.size();
    int n=m;
    int t[m+1][n+1],i,j;
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0 || j==0)
              t[i][j]=0;
            else if(a[i-1]==b[j-1])
              t[i][j]=1+t[i-1][j-1];
            else
              t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
    }
    return m-t[m][n];
} 
