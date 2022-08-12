#include<iostream>
using namespace std;

class item{
public:
  static int number;
  void test()
  {
     number++;
  }
  void print_data()
  {
    cout<<number<<endl;
  }
};
int item::number=100;
int main()
{
  item a;
  a.print_data();
  a.test();
  a.print_data();
  cout<<a.number<<endl;
  cout<<item::number<<endl;

}
