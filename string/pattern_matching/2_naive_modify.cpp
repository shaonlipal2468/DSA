#include<bits/stdc++.h>
using namespace std;

int main()
{
  string text = "ABABDABACDABABCABAB";
  string pattern ="AB";

  int N= text.size();
  int M = pattern.size();

  int i=0;
  int j;
  while(i<=N-M)
  {

    for(j=0;j<M;j++)
       if(text[i+j]!=pattern[j])
          break;

    if(j==M)
    {
      cout<<"found at "<<i<<endl;
      i=i+M;
    }


    else if(j==0)
       i++;
    else
       i=i+j;

  }
}
