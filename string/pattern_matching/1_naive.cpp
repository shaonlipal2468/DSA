#include<bits/stdc++.h>
using namespace std;

int main()
{
  string text = "ABABDABACDABABCABAB";
  string pattern ="AB";

  int N= text.size();
  int M = pattern.size();

  for(int i=0;i<=N-M;i++)
  {
    int j;
    for(j=0;j<M;j++)

       if(text[i+j]!=pattern[j])
          break;

       if(j==M)
         cout<<"found at "<<i<<endl;
  }
}
