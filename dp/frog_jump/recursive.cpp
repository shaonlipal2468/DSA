#include<bits/stdc++.h>
using namespace std;
int fun(vector<int> &arr,int index)
{
    if(index==0)
        return 0;
    else if(index==1)
        return abs(arr[1]-arr[0]);
    int left = fun(arr,index-1)+abs(arr[index]-arr[index-1]);
    int right=fun(arr,index-2)+abs(arr[index]-arr[index-2]);
    return min(left,right);  
}
int main()
{
   vector<int> heights = {30,10,60,10,60,50};
   int n = heights.size();
   cout<<fun(heights,n-1);
}
