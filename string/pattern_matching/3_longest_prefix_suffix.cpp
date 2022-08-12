#include <bits/stdc++.h>
using namespace std;
int main()
{
   //string str ="acbacdabcy";
   string str = "gigummcnu";
   //string str = "vuhxwv";
   int length = str.size();
   int lps[length];
   lps[0]=0;
   int i,j;
   i=0,j=1;
   while(j<length)
   {
       if(str[i]==str[j])
       {
           lps[j]=i+1;
           i++;
           j++;
       }
       else
       {
          if(i!=0)
            i=lps[i-1];
          else
            {
                lps[j]=0;
                j++;
            }
       }
   }
   for(i=0;i<length;i++)
     cout<<lps[i]<<" ";
    cout<<endl;
}
