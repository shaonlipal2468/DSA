#include<iostream>
using namespace std;

class item{
  int number;
  float cost;
public:
  void getdata(int x,float y)
  {
     number=x;
     cost=y;
  }
  void print_data()
  {
    cout<<number<<" "<<cost<<endl;
  }
  void hello();
};

void item::hello(){
  cout<<"hello";
}
int main()
{
  item I;
  I.getdata(3,4.0);
  I.print_data();
  I.hello();
}
