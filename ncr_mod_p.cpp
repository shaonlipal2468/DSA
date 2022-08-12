#include<iostream>
using namespace std;
int n =1000;
int dp[1001];
const int p =1e9+7;

int power(int a, int n)
{
    int res = 1;
    while (n)
    {
        if (n&1)
            res = (res * a)%p;
        // y = y/2
        a=(a*a)%p;
        n=n>>1;
    }
    return res;
}

int solve(int n,int k)
{
  if(k>n)
    return 0;
  int res = dp[n];
  res = (res* 1LL*power(dp[k],p-2))%p;
  res = (res*1LL*power(dp[n-k],p-2))%p;
  return res;
}

int main()
{
  dp[0]=dp[1]=1;
  for(int i=2;i<=1000;i++)
     dp[i]= (dp[i-1]*1LL*i)%p;

  cout<<power(2,5)<<endl;
   for(int i=0;i<=10;i++)
      cout<<dp[i]<<" ";
   cout<<endl;
  int t;
  while(t--)
  {
     int n,k;
     cin>>n>>k;
     cout<<solve(n,k)<<endl;
  }
}
