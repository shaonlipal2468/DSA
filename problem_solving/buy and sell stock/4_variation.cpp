/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete as many transactions
 as you like (i.e., buy one and sell one share of the stock multiple times)
 with the following restrictions:
After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously
(i.e., you must sell the stock before you buy again).
Example 1:
Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
*/
//Best Time to Buy and Sell Stock with Cooldown

#include<bits/stdc++.h>
using namespace std;
int max_of_three(int n1,int n2,int n3)
    {
       return n1>n2 ? (n1>n3 ? n1:n3) : (n2>n3 ? n2: n3);
    }

int maxProfit(int prices[],int n) {
if(n==1)
        return 0;
  int old_buy_state_profit = -prices[0];
  int old_sell_state_profit = 0;
  int old_cooldown_state_profit=0;

  int new_buy_state_profit,new_sell_state_profit,new_cooldown_state_profit;
  for(int i=1;i<n;i++)
  {
      new_buy_state_profit=max(old_buy_state_profit,
                            old_cooldown_state_profit-prices[i]);

      new_sell_state_profit=max(old_sell_state_profit,
                             old_buy_state_profit +prices[i]);

      new_cooldown_state_profit = max(old_cooldown_state_profit,
                                   old_sell_state_profit  );


      old_buy_state_profit=new_buy_state_profit;
      old_sell_state_profit=new_sell_state_profit;
      old_cooldown_state_profit=new_cooldown_state_profit;
  }
  return max_of_three(new_buy_state_profit,
                      new_sell_state_profit,
                      new_cooldown_state_profit);
    }

int main()
{
  int arr[]={1,2,3,0,2};
  int n=sizeof(arr)/sizeof(arr[0]);
  cout<<"Maximum profit wih cool down is "<< maxProfit(arr,n)<<endl;
}
