/*
n=0100
k:3210 (index from LSB)
k=2  (set)

1<<(2) : 2 times left shift of 1
0001
0010
0100

0100 & 0100 = 0100 > 0  so kth bit is set
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool checkKthBit(int n, int k){

    // Your code here
    // It can be a one liner logic!! Think of it!!
    if(n& (1<<(k)))
       return true;
    return false;
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
  bool pre = s.checkKthBit(n,k);
  cout<<pre;





}
