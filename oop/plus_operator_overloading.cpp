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
  complex operator+(complex c)
  {
    complex temp;
    temp.a= a+c.a;
    temp.b= b+c.b;
    return temp;

  }
};

int main()
{
  complex c1,c2,c3,c4;
  c1.setdata(3,4);
  c2.setdata(5,6);
  c3=c1+c2;
  c3.display();

  c4=c1.operator+(c2);
  c4.display();

}
