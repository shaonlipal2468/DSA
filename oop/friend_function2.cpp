#include<iostream>
using namespace std;
class B;  //forward declaration
class A{
  int a;
public:
  void setdata(int x){
    a=x;
  }
  friend void fun(A,B);
};

class B{
  int b;
public:
  void setdata(int x){
    b=x;
  }
  friend void fun(A,B);
};

void fun(A o1,B o2)
{
  cout<<"sum is "<< o1.a+o2.b<<endl;
}

int main()
{
  A o1;
  o1.setdata(3);
  B o2;
  o2.setdata(4);
  fun(o1,o2);
}
