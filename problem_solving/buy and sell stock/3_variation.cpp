/*
You are given an array prices where prices[i] is the price of a given stock on the ith day,
 and an integer fee representing a transaction fee.
Find the maximum profit you can achieve. You may complete as many transactions
as you like, but you need to pay the transaction fee for each transaction.
Note: You may not engage in multiple transactions simultaneously
(i.e., you must sell the stock before you buy again).

Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
*/
#include<bits/stdc++.h>
using namespace std;
int maxProfit(int prices[],int n, int fee) {
        if(n==1)
             return 0;
        // 4 variables
        int old_buy_state_profit=-prices[0];
        int old_sell_state_profit = 0;
        int new_buy_state_profit,new_sell_state_profit;

        for(int i=1;i<n;i++)
        {
            new_buy_state_profit = max(old_buy_state_profit,
                                       old_sell_state_profit-prices[i]);
            new_sell_state_profit=max(old_sell_state_profit,
                                      old_buy_state_profit+prices[i]-fee);
            old_buy_state_profit = new_buy_state_profit;
            old_sell_state_profit = new_sell_state_profit;
        }
        return max(new_sell_state_profit,new_buy_state_profit);
    }

int main()
{
  int arr[]={1,3,2,8,4,9};
  int fee=2;
  int n=sizeof(arr)/sizeof(arr[0]);
  cout<<"Maximum Profit is : "<<maxProfit(arr,n,fee)<<endl;
}
