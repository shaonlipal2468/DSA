/*
n=0100
k:3210 (index from LSB)
k=0

1<<(0) : 0 times left shift of 1
0001


0100 | 0001 = 0101 = 5
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    unsigned int setKthBit(unsigned int n, int k){

    // Your code here
    // It can be a one liner logic!! Think of it!!
    n = n | (1<<(k));
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
  unsigned int pre = s.setKthBit(n,k);
  cout<<pre;

}
