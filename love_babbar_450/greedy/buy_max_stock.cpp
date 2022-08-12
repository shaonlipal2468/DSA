//Buy Maximum Stocks if i stocks can be bought on i-th day(just like fractional knapsack problem)

#include<bits/stdc++.h>
using namespace std;

int buyMaximumProducts(int n,int k,int price[])
{
  vector<pair<int, int> > v;

   // Making pair of product cost and number of day..
   for (int i = 0; i < n; ++i)
       v.push_back(make_pair(price[i], i + 1));

   sort(v.begin(), v.end());
   int ans =0;
   for (int i = 0; i < n; ++i)
   {
      if(v[i].first *v[i].second<=k)
      {
         ans+=v[i].second;
         k=k-v[i].first *v[i].second;
      }
      else
      {
        ans+= k/v[i].first;
        break;
      }
   }
    return ans;
}

int main()
{
 int price[] = { 10, 7, 19 };
 int n = sizeof(price)/sizeof(price[0]);
 int k = 45;

 cout << buyMaximumProducts(n, k, price) << endl;

}
