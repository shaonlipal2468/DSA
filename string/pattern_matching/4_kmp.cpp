
#include <bits/stdc++.h>
using namespace std;

void computeLPSArray(char* pat, int M, int* lps);

// Prints occurrences of txt[] in pat[]
void KMPSearch(char* pat, char* txt)
{
	int M = strlen(pat);
	int N = strlen(txt);

	// create lps[] that will hold the longest prefix suffix
	// values for pattern
	int lps[M];

	// Preprocess the pattern (calculate lps[] array)
	computeLPSArray(pat, M, lps);

	int i = 0; // index for txt[]
	int j = 0; // index for pat[]
	while (i < N) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}

		if (j == M) {
			cout<<"Found pattern at index "<<i - j<<endl;
			j = lps[j - 1];
		}

		// mismatch after j matches
		else if (i < N && pat[j] != txt[i]) {
			// Do not match lps[0..lps[j-1]] characters,
			// they will match anyway
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
}

// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(char* str, int length, int* lps)
{
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
}

// Driver program to test above function
int main()
{
	char txt[] = "ABABDABACDABABCABAB";
	char pat[] = "ABABCABAB";
	KMPSearch(pat, txt);
	return 0;
}
