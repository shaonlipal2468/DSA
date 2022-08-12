#include<bits/stdc++.h>
using namespace std;

string remove_duplicates(string str)
{
 string out;
 int i;
 sort(str.begin(),str.end());
 int length = str.length();
 for(i=0;i<length;i++)
 {
   if(str[i]!=str[i+1])
       out.push_back(str[i]);
 }
 return out;
}


int main()
{
  string s;
  getline(cin,s);
  string output = remove_duplicates(s);
  cout<<output<<endl;
}
