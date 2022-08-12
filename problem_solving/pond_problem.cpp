/*
There are N floating blocks in a pond and they are arranged in a straight line.
Each of these blocks has a value associated with them which is written on top of them.
After every 1 minute, blocks at the odd positions get submerged underwater.
You must shift the remaining blocks to one position left to fill in the emptied space.
This process is repeated till only one block is left floating.
You must retum the value of the last block which is left floating.
Note: The position index starts with 1 and blocks are numbered
from 1 to N in the left to right direction. It is
given that N is always greater than 1

Answer:
If the input number N is in power of 2 , output will be N
else if the number is not in power of 2(let say 2ᵃ + z ) , output will be 2ᵃ
Explanation:
1st case :N=4
1 2 3 4
2 4
4(output)
2nd case : N=9 (i.e. (2³)+1 )
1 2 3 4 5 6 7 8 9
2 4 6 8
4 8
8 (=2³)
*/

#include <bits/stdc++.h>

using namespace std;
bool isPowerOfTwo(int n) {
        if(n<0)
            return false;
        if(n==1)
            return true;
        if(n==0)
            return false;
        while(n>1)
        {
            if(n%2==1)
                return false;
            n=n/2;
        }
        return true;

    }

int func(int N)
{
    if(isPowerOfTwo(N))
      return N;
    else
    {
        int x= floor(log2(N));
        return pow(2,x);
    }

}

int main()
{
   cout << func(22) << endl;

   return 0;
}
