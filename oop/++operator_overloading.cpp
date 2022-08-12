#include<iostream>
using namespace std;

class integer
{
  int x;
public:
  void setdata(int a)
  {
    x=a;
  }
  void display()
  {
    cout<<x<<endl;
  }

  integer operator++() //pre increment
  {
    integer temp;
    temp.x=++x;
    return temp;
  }
  integer operator++(int)
  //int is written as argument so that
  // compiler can differentiate between pre and post increment
  //ar kono kaj nei
  {
    integer temp;
    temp.x=x++;
    return temp;
  }

};

int main()
{
  integer i1,i2;
  i1.setdata(2);
  i2=++i1;

  i2.display();
  i1.display();


  integer i3;
  i3=i1++;
  i3.display();
  i1.display();

}
