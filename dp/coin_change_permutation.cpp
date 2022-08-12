#include<bits/stdc++.h>
using namespace std;

void coin_change_permutation(vector<int> coins,int coin,int target)
{
  int size= target+1;
  int table[size]={0};
  table[0]=1;

  for(int amt=1;amt<size;amt++)
  {
    for(auto coin:coins)
    {
      if(coin<= amt)
      {
        int remain_amt= amt-coin;
        table[amt]+=table[remain_amt];
      }
    }
  }

cout<<table[target]<<endl;
}



int main()
{
    vector<int> coins = {2,3,6,5};
    int m = coins.size();
    int n = 10;
    coin_change_permutation(coins, m, n);
    return 0;
}
