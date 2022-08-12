#include<bits/stdc++.h>
using namespace std;
void print_ans(vector<int> ans,int arr[],int n)
{
  for(int i=0;i<ans.size();i++)
     cout<<arr[i]<<" : "<<ans[i]<<endl;
  cout<<endl;
}
vector<int> next_greater_left(int arr[],int n)
{
  stack<int> s;
  vector<int> ans(n);
  s.push(arr[0]);
  ans[0]=-1;
  for(int i=1;i<n;i++)
  {
    while(s.size()>0 && arr[i]<=s.top() )
       s.pop();
     if(s.size()==0)
        ans[i]=-1;
     else
        ans[i]= s.top();
     s.push(arr[i]);
  }
  return ans;
}
int main()
{
  int arr[]={11,13,21,4,78,99,4,10};
  int n=sizeof(arr)/sizeof(arr[0]);
  vector<int> ans = next_greater_left(arr,n);
  print_ans(ans,arr,n);

}
