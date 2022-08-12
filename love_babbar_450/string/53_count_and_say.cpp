#include<bits/stdc++.h>
using namespace std;

string count_and_say(int n)
{
   if(n==1)
     return "1";
   else if(n==2)
     return "11";
   string ans ="11";
   for(int i=3;i<=n;i++)
   {
     int count =1;
     int len = ans.size();
     for(int j=1;j<len;j++)
     {
        if(ans[j]!=ans[j-1])
        {
          ans = to_string(count)+ans[j-1];
          count=1;
        }
        else
          count++;
        if(j==len-1)
         ans = to_string(count)+ans[j];
     }
       cout<<i<<" "<<ans<<endl;
   }
   return ans;
}

int main()
{
  int n;
  cin>>n;
  count_and_say(n);
}
