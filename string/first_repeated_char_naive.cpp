// C++ program to find the fist
// character that is repeated
#include <bits/stdc++.h>
#include <string.h>

using namespace std;
int findRepeatFirstN2(string s)
{
	// this is O(N^2) method
	int length = s.length();
	cout<<length<<endl;
	int p = -1, i, j;
	for (i = 0; i < length; i++)
	{
		for (j = i + 1; j < length; j++)
		{
			if (s[i] == s[j])
			{
				p = i;
				break;
			}
		}
		if (p != -1)
			break;
	}

	return p;
}

// Driver code
int main()
{
	string str;
	getline(cin,str);
	//char str[] = "geeksforgeeks";
	int pos = findRepeatFirstN2(str);
	if (pos == -1)
		cout << "Not found";
	else
		cout << str[pos];
	return 0;
}
