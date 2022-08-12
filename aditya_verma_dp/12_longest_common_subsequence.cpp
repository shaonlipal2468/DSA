  #include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

int lcs(int, int, string, string);
int lcs_bottom_up(int, int, string, string);

int main()
{
    int t,n,k,x,y;

    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input

        cout << lcs_bottom_up(x, y, s1, s2) << endl;
    }
    return 0;
}
// } Driver Code Ends


// function to find longest common subsequence

int lcs(int x, int y, string s1, string s2){

    // your code here
    if(x==0 || y==0)
      return 0;
    if(s1[x-1] == s2[y-1])
       return 1+lcs(x-1,y-1,s1,s2);
    else
       return max(lcs(x-1,y,s1,s2),lcs(x,y-1,s1,s2));

}
int lcs_bottom_up(int x, int y, string s1, string s2){

    // your code here
    int t[x+1][y+1],i,j;
    for(i=0;i<=x;i++)
    {
        for(j=0;j<=y;j++)
        {
            if(i==0 || j==0)
                 t[i][j]=0;
            else if(s1[i-1] == s2[j-1])
               t[i][j]= 1+t[i-1][j-1];
            else
               t[i][j]= max(t[i-1][j],t[i][j-1]);
         }
    }
    vector<char> lcs;
    i=x;
    j=y;
    while(i>0 && j>0)
    {
      if(s1[i-1]==s2[j-1])
      {
        lcs.push_back(s1[i-1]);
        i--;
        j--;
      }
      else{
        if(t[i-1][j] > t[i][j-1])
           i--;
        else j--;
      }
    }
    for(i=lcs.size()-1;i>=0;i--)
       cout<<lcs[i];
    cout<<endl;
    return t[x][y];
}
