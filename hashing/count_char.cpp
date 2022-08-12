#include<bits/stdc++.h>
using namespace std;

void print_Count(string s)
{
  map<char,int> m;
  for(auto x:s)
  {
    m[x]++;
  }
  for(auto x:m)
  {
    cout<< x.first<<" "<<x.second<<endl;
  }
}


int main()
{
  string input ;
  getline(cin,input);
  print_Count(input);
}
