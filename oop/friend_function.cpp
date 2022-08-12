#include<iostream>
using namespace std;

class complex{
  int a,b;
public:
  void setdata(int x,int y)
  {
    a=x;
    b=y;
  }
  void display()
  {
    cout<<a<<"+i"<<b<<endl;
  }
  friend void fun(complex c)
  {
    cout<<"sum is "<<c.a+c.b<<endl;
  }

};

int main()
{
  complex c1,c2;
  c1.setdata(3,4);
  fun(c1);
  
}
