//sum of two numbers without using
#include<iostream>
using namespace std;

int sum(int x , int y)
    {
  while (y != 0)
    {
        int carry = x & y;
        x = x ^ y;
        y = carry << 1;
    }
    return x;
}

int main()
{
int x=50;
int y=30;
cout<<sum(x,y);
}
