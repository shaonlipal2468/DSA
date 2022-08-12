#include<bits/stdc++.h>
using namespace std;
int max_two(int a,int b)
  {
      return a>b?a:b;
  }
bool checkZeroOnes(string s) {
     int number_zero=0;
     int number_one=0;
     if(s[0]=='0')
         number_zero++;
     else
         number_one++;

     int zero_max=INT_MIN;
     int one_max=INT_MIN;
     for(int i=1;i<s.size();i++)
     {
         if(s[i-1]=='0' && s[i]=='0')
             number_zero++;
         else if(s[i-1]=='0' && s[i]=='1')
         {
             zero_max=max_two(zero_max,number_zero);
             number_zero=0;
             number_one=1;
         }

         else if(s[i-1]=='1' && s[i]=='0')
         {
             one_max=max_two(one_max,number_one);
             number_one=0;
             number_zero=1;
         }
         else
             number_one++;
    }
     zero_max=max_two(zero_max,number_zero);
     one_max=max_two(one_max,number_one);

     if(one_max>zero_max)
         return true;
     return false;

 }
int main()
{
  //string s="111000";
  string s="01100100110";
  cout<<checkZeroOnes(s);
}
