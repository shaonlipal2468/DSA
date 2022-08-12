/*
n=1100
k:3210 (index from LSB)
k=2

1<<(2) : 0 times left shift of 1
0001
0010
0100

~(0100) =1011

1100 & 1011 = 1000 = 8
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    unsigned int clearKthBit(unsigned int n, int k){

    // Your code here
    // It can be a one liner logic!! Think of it!!
    n = n & ~(1<<(k));
    return n;
    }
};
int main()
{
  int k;
  cout<<"enter k :";
  cin>>k;

  unsigned int n;
  cout<<"enter the input :";
  cin>>n;

  Solution s;
  unsigned int pre = s.clearKthBit(n,k);
  cout<<pre;

}
