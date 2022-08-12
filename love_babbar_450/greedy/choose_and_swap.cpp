#include<bits/stdc++.h>
using namespace std;
string chooseandswap(string a){
    // Code Here
    set <char> s;
    for(int i=0;i<a.length();i++)
      s.insert(a[i]);

    for(int i=0;i<a.length();i++)
    {
        s.erase(a[i]);
        if(s.empty())
            break;
        else
        {
            char ch=*s.begin();
            if(ch<a[i])
            {
                char ch2 = a[i];
                for(int j=0;j<a.length();j++)
                {
                    if(a[j]==ch)
                       a[j]=ch2;
                    else if(a[j]==ch2)
                       a[j]=ch;
                }
            break;
            }
        }
    }
    return a;
}
int main()
{
  string a ="ccad";
  cout<<chooseandswap(a)<<endl;
}
