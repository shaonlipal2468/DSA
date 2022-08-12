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
  friend complex operator+(complex,complex);

};

complex operator+(complex o1,complex o2)
{
    complex temp;
    temp.a= o1.a+o2.a;
    temp.b= o1.b+o2.b;
    return temp;
}
int main()
{
  complex c1,c2,c3,c4;
  c1.setdata(3,4);
  c2.setdata(5,6);
  c3=c1+c2;
  c3.display();

  c4=operator+(c1,c2);
  c4.display();

}
