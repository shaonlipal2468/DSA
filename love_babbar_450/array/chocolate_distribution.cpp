#include<bits/stdc++.h>
using namespace std;
int findMinDiff(vector<int> a, int n, int m){
  //code
  sort(a.begin(),a.end());
  int res=INT_MAX;
  for(int i=0;i<(n-m+1);i++)
  {
      int temp=a[i+m-1]- a[i];
      res=min(res,temp);
  }
  return res;
  }


  int main()
  {
  vector<int> arr={3, 4, 1, 9, 56, 7, 9, 12};
  int n=8;
  int m=5;
  int ans = findMinDiff(arr,n,m);
  cout<<ans;
  }
