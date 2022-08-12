#include<iostream>
using namespace std;

int count=0;
class test{
public:
  test()
  {
    count++;
    cout<<"constructor called"<<endl;
  }
  ~test()
  {
    count--;
    cout<<"destructor called"<<endl;
  }
};

int main()
{
  test t1,t2;

}
