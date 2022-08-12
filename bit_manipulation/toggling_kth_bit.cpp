/*
EXAMPLE 1:
n=0100
k:3210 (index from LSB)
k=1

1<<(1) : 1 times left shift of 1
0001
0010

0100 ^(XOR) 0010 = 0110 = 6

EXAMPLE 2: 
n=0110
k:3210 (index from LSB)
k=1

1<<(1) : 1 times left shift of 1
0001
0010

0110 ^(XOR) 0010 = 0100 = 4


*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    unsigned int togglingKthBit(unsigned int n, int k){

    // Your code here
    // It can be a one liner logic!! Think of it!!
    n = n ^ (1<<(k));
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
  unsigned int pre = s.togglingKthBit(n,k);
  cout<<pre;

}
