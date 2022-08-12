/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and
 choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0

SOLUTION :
We need to find out the maximum difference (which will be the maximum profit) between 
two numbers in the given array. Also, the second number (selling price) must be larger than
the first one (buying price).
In formal terms, we need to find max(prices[j]-prices[i]), for every i and j such that j > i.

EXAMPLE:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
*/

//Only one transaction allowed
#include<bits/stdc++.h>
using namespace std;

int maxProfit(int prices[],int n)
{
	int maxprofit=0;
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(prices[j]>prices[i])
			maxprofit=max(maxprofit,prices[j]-prices[i]);
		}
	}
	return maxprofit;
}

//improved
int maxProfit_improved(int prices[],int n) {
        int profit=0;
        int min_ele = prices[0];
        
        for(int i=1;i<n;i++)
        {
            if(prices[i]<min_ele)
                min_ele=prices[i];
            else
                profit=max(profit,prices[i]-min_ele);
        }
        return profit;
    }

int main()
{
	int prices[]={7,1,5,3,6,4};
	int n=sizeof(prices)/sizeof(prices[0]);
	cout<<maxProfit_improved(prices,n);
}

