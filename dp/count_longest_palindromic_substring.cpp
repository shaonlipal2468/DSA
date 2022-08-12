#include<bits/stdc++.h>
using namespace std;
int count_longest_palindromic_substring(string str)
{
  int n = str.size();
  int count=0;
  int length =0; //length of longest palindromic substring
  bool dp[n][n];
  for(int gap=0;gap<n;gap++)
  {
      for(int i=0,j=gap;j<n;i++,j++)
      {
          if(gap == 0)
             dp[i][j] = true;
          else if(gap==1)
          {
              if(str[i]==str[j])
                 dp[i][j]=true;
              else
                 dp[i][j]=false;
          }
          else
          {
              if(str[i]==str[j] && dp[i+1][j-1])
                  dp[i][j]=true;
              else
                  dp[i][j]=false;
          }

          //printing palindromic substring//not important
          if(dp[i][j])
          {
            count++;
            length = gap+1;  //or j-i+1
            cout<<i<<" "<<j<<" ";
            if(i==j)
               cout<<str[i]<<endl;
            else
               cout<<str.substr(i,j-i+1)<<endl;
          }

      }
  }
  cout<<"longest length is "<<length<<endl;
  return count;
}

int main()
{
  string str ="vnrtysfrzrmzlygfv";
  cout<<count_longest_palindromic_substring(str)<<endl;

  int n=5;
  for(int gap=0;gap<n;gap++)
      for(int i=0,j=gap;j<n;i++,j++)
            cout<<i<<" "<<j<<endl;


}
