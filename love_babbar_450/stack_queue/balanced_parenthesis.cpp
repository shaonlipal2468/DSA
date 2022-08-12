#include<bits/stdc++.h>
using namespace std;
bool ispar(string s)
    {
        stack<char> st;
        // Your code here
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                 st.push(s[i]);
            else if(s[i]==')')
                 {
                     if(st.size()==0)
                       return false;
                     else if(st.top()!='(')
                        return false;
                     else
                       st.pop();
                 }
            else if(s[i]=='}')
                {
                    if(st.size()==0)
                       return false;
                    else if(st.top()!='{')
                        return false;
                    else
                       st.pop();
                }
            else if(s[i]==']')
                {
                    if(st.size()==0)
                       return false;
                    else if(st.top()!='[')
                       return false;
                    else
                       st.pop();
                }
        }
        if(st.size()==0)
          return true;
        else return false;
    }
int main()
{
  string s = "[{()}]";
  cout<<ispar(s);
}
