//https://www.geeksforgeeks.org/calculate-square-of-a-number-without-using-and-pow/
#include<bits/stdc++.h>
using namespace std;

int square(int n)
{
  if(n==0)
    return 0;
  if(n<0)
    n=-n;
  int x = n>>1; // n/2

  if(n&1) //odd number  //4x^2+ 4x +1
     return  (square(x)<<2) + (x<<2)+1;
  else //even number 2x+1
     return square(x)<<2;
}

int square_new(int n)
{
  int temp = n;
  int res=0;
  int pos=0;

  while(temp)
  {
    if(temp&1)
       res += (n<<pos);
    pos++;
    temp>>=1;
  }
   return res;
}

int main()
{
   int n = 7;
   cout<<square_new(n)<<endl;

}
