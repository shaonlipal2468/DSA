#include<iostream>
using namespace std;


class Dummy{
  int a,b;
public:
  void setData(int x,int y)
  {
    a=x;
    b=y;
  }
  void showData()
  {
    cout<<a<< " "<<b<<endl;
  }
};

int main()
{
  Dummy d1;
  d1.setData(3,4);
  Dummy d2= d1;   //shallow copy
  Dummy d3;
  d3=d1;   //deep copy
  d2.showData();
}
