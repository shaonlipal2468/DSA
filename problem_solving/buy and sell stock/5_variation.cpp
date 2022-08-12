/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete at most two transactions.
Note: You may not engage in multiple transactions simultaneously
(i.e., you must sell the stock before you buy again).
Example 1:
Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
*/

//Best Time to Buy and Sell Stock by atmost 2 transactions
#include<bits/stdc++.h>
using namespace std;
int maxProfit(int prices[],int n) {
    if(n==1)
        return 0;

    int dp_left[n],dp_right[n];
    dp_left[0]=0;
    dp_right[n-1]=0;

    int least_so_far = prices[0];
    int max_after_today = prices[n-1];

    for(int i=1;i<n;i++)
    {
        least_so_far = min(least_so_far,prices[i]);
        dp_left[i]= max( prices[i]-least_so_far ,dp_left[i-1]);
    }

    for(int i=n-2;i>=0;i--)
    {
        max_after_today = max(max_after_today,prices[i]);
        dp_right[i]= max( max_after_today-prices[i] ,dp_right[i+1]);
    }
    int max_profit=0;
    for(int i=0;i<n;i++)
        max_profit=max(max_profit,dp_left[i]+dp_right[i]);
    return max_profit;
}
int main()
{
  int arr[]={1,3,2,8,4,9};
  int n=sizeof(arr)/sizeof(arr[0]);
  cout<<maxProfit(arr,n);
}
