#include<bits/stdc++.h>
using namespace std;
int fun(vector<int> &arr)
{
    int n = arr.size();
   
    int prev2=0;
    int prev1= abs(arr[1]-arr[0]);
    for(int i=2;i<n;i++)
    {
       int left = prev1+abs(arr[i]-arr[i-1]);
       int right = prev2+abs(arr[i]-arr[i-2]);
       int curr= min(left,right);
       prev2 = prev1;
       prev1= curr;
       
    }
    
    return prev1;
}

int main()
{
   vector<int> heights = {30,10,60,10,60,50};
   cout<<fun(heights);
}
