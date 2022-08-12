#include<iostream>
using namespace std;
class student{
  int roll;
  int marks;
public:
  student(){}  //default constructor
  student(int r,int m) //parameterized constructor
  {
    roll=r;
    marks=m;
  }
  student(student &s) //copy constructor
  {
    roll=s.roll;
    marks = s.marks;
  }
  void display(){
    cout<< roll<<" "<<marks<<endl;
  }
};

int main()
{
  student s1(1,59);
  student s2=s1; //shallow copy
  student s3;
  s3=s1; //deep copy

  s1.display();
  s2.display();
  s3.display();
}
