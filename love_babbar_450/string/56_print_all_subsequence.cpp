# include <bits/stdc++.h>
using namespace std;

void printSubsequence(string input, string output)
{
  if(input.length() == 0)
  {
    cout<<output<<endl;
    return;
  }
  char ch= input[0];
  string rest_of_input = input.substr(1);
  printSubsequence(rest_of_input,output+ch);
  printSubsequence(rest_of_input,output);
}

void print_Subsequence(string input)
{
  int n = input.size();
  for(int i=0;i<n;i++)
  {
    for(int j=i;j<n;j++)
    {
      cout<<input.substr(i,j-i+1)<<endl;
    }
  }
}
int main()
{
    // output is set to null before passing in as a
    // parameter
    string output = "";
    string input = "abc";
    printSubsequence(input, output);
    cout<<"**************"<<endl;
    print_Subsequence(input);
    return 0;
}
