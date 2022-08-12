//https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<bits/stdc++.h>
#define MOD 1000000007
int countDistinctWays(int n) {
    //  Write your code here. 
    int prev2=1,prev1=1;
    for(int i=2;i<=n;i++)
    {
        int curr= (prev1+prev2)%MOD;
        prev2 = prev1;
        prev1=curr;
    }
    return prev1;
}

int main()
{
  int n;
  cin>>n;
  cout<<countDistinctWays(n)<<endl;
}
