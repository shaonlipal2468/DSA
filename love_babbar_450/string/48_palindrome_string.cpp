#include<bits/stdc++.h>
using namespace std;
    int isPlaindrome(string S)
  	{
  	    // Your code goes here
  	    int low=0;
          int high=S.size()-1;

          while(low<=high)
          {
              if(S[low]!=S[high])
                 return 0;
              low++;
              high--;
          }
          return 1;
  	}
int main()
{
   string S ="abba";
   cout<<isPlaindrome(S);

}
