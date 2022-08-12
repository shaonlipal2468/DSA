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
  friend complex operator-(complex);

};

complex operator-(complex c)
{
    complex temp;
    temp.a= -c.a;
    temp.b= -c.b;
    return temp;
}

int main()
{
  complex c1,c3,c4;
  c1.setdata(3,4);
  c3=-c1; //first way
  c3.display();
  c4=operator-(c1); //second way
  c4.display();

}
