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
    cout<<a<<"+i("<<b<<")"<<endl;
  }
  complex operator-()
  {
    complex temp;
    temp.a= -a;
    temp.b= -b;
    return temp;

  }
};

int main()
{
  complex c1,c3,c4;
  c1.setdata(3,4);
  c3=-c1; //first way
  c3.display();
  c4=c1.operator-(); //second way
  c4.display();

}
