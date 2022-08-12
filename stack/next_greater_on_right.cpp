#include<bits/stdc++.h>
using namespace std;
void print_ans(vector<int> ans,int arr[],int n)
{
  for(int i=0;i<ans.size();i++)
     cout<<arr[i]<<" : "<<ans[i]<<endl;
  cout<<endl;
}
vector<int> next_greater_right(int arr[],int n)
{
  stack<int> s;
  vector<int> ans(n);
  s.push(arr[n-1]);
  ans[n-1]=-1;
  for(int i=n-2;i>=0;i--) //for each element pops, answer , push
  {
    while(s.size()>0 && arr[i]>=s.top() ) //small elements will be popped out
       s.pop();
     if(s.size()==0) //all elements are popped ..meaning this arr[i] bigger than those popped elements
     //so its next next_greater_right is -1
        ans[i]=-1;
     else
        ans[i]= s.top(); //someone bigger than arr[i] is in top of stack
     s.push(arr[i]);
  }
  return ans;
}
int main()
{
  int arr[]={11,13,21,4,78,99,4,10};
  int n=sizeof(arr)/sizeof(arr[0]);
  vector<int> ans = next_greater_right(arr,n);
  print_ans(ans,arr,n);

}
