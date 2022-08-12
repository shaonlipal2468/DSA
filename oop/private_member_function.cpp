#include<iostream>
using namespace std;


class sample{
  int num;
  void read();
  void read1()
  {
    read();
  }
  //private member function can be called by another member function of class

public:
  void update();

};

void sample::read()
{
  cout<<"hello"<<endl;
}

void sample::update()
{
  read();
  read1();
}

int main()
{
  sample s;
//  s.read(); // illegal
  s.update();

}
