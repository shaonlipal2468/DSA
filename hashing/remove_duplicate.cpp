#include<bits/stdc++.h>
using namespace std;

string remove_duplicates(string str)
{
  int length=str.length();
  string out;
  int i,j;
  for(i=0;i<length;i++)
  {
    for(j=0;j<i;j++)
    {
      if(str[i]==str[j])
         break;

    }
    if(i==j)
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
