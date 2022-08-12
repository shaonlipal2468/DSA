#include<bits/stdc++.h>
using namespace std;
vector<int> candyStore(int candies[], int n, int k)
    {
        // Write Your Code here
        int min=0,max=0;
        sort(candies,candies+n);

        int i=0;
        int j=n-1;
        while(i<=j)
        {
            min+=candies[i];
            i++;
            j=j-k;
        }
        reverse(candies,candies+n);
        i=0;
        j=n-1;
        while(i<=j)
        {
            max+=candies[i];
            i++;
            j=j-k;
        }
        return {min,max};
    }
    int main()
    {
       int n = 4;
       int k=2;
       int candies[] = {3, 2, 1, 4};
       vector<int> v(2);
       v=candyStore(candies,n,k);
       cout<<v[0]<<" "<<v[1]<<endl;
    }
