//geeksforgeeks output will be e
//Find the first repeated character in a string

#include<bits/stdc++.h>
using namespace std;
// Driver code
int first_repeated_char(string s)
{
  int length= s.length();
  int count[256]={0};

  for(int i=0;i<length;i++)
{
    if(count[s[i]]==1)
        return i;
    else
        count[s[i]]++;
}
return -1;
}

int main()
{
	string str;
	getline(cin,str);
	//char str[] = "geeksforgeeks";
	int pos = first_repeated_char(str);
	if (pos == -1)
		cout << "Not found";
	else
		cout << str[pos];
	return 0;
}
