#include<bits/stdc++.h>
using namespace std;

void power_Set(string s,int index,string curr)
{
   if(index==s.size())
   {
     cout<<curr<<endl;
     return;
   }
   power_Set(s,index+1,curr+s[index]);
   power_Set(s,index+1,curr);
}


int main()
{
   string s ="abc";
   power_Set(s,0,"");
}
