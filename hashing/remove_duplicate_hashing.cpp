//remove duplicates using hasing

#include<bits/stdc++.h>
using namespace std;
string remove_duplicates(string str)
{
  string out;
  unordered_map<char,bool> hash;
  for(auto x:str)
  {
     if(hash.find(x) == hash.end())
      {
           out.push_back(x);
           hash[x] = true;
      }
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
