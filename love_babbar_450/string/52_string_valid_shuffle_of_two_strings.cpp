#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s1,s2,res;
  cin>>s1>>s2>>res;

  int l1= s1.length();
  int l2= s2.length();
  int l3= res.length();
  if(l1+l2!=l3)
  {
     cout<<"NO"<<endl;
     return 0;
  }

  int i=0,j=0,k=0;
  while(k<l3)
  {
     if(i<l1 && s1[i]==res[k])
        i++;
     else if(j<l2 && s2[j]==res[k])
        j++;
     else
     {
       cout<<"NO"<<endl;
       return 0;
     }
     k++;
  }
  cout<<"YES"<<endl;
}
