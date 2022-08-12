#include <bits/stdc++.h>
#include"declarations.cpp"
using namespace std;

class Queue{
public:
  Stack<int> s1,s2;
  void enQueue(int);
  int deQueue();
};
//queue operation take O(1) time
void Queue::enQueue(int data)
{
    s1.push(data);
}
//dequeue operation takes O(n) time
int Queue::deQueue()
{
  //if both are empty then underflow
  if(s1.isEmpty()==1 && s2.isEmpty()==1)
     {
       cout<<"Queue is empty"<<endl;
       return -1;
     }
  //transfer all element from s1 to s2
  while(s1.isEmpty()!=1)
  {
    int temp = s1.pop();
    s2.push(temp);
  }
  //pop the top element of s2
  int ans = s2.pop();
  //again tranfer remaining element from s2 to s1
  while(s2.isEmpty()!=1)
  {
    int temp = s2.pop();
    s1.push(temp);
  }
  return ans;
}


int main(){
  int choice,data,temp;
  Queue q;

  do
  {
    cout<<"****************************************\n";
    cout<<"1. enqueue\n";
    cout<<"2. deQueue\n";
    cout<<"3. Exit\n";

    cout<<"enter ur choice\n";
    cin>>choice;

    switch (choice) {
      case 1:cout<<"enter data :"<<endl;
             cin>>data ;
             q.enQueue(data);
             break;


      case 2:temp = q.deQueue();
             if(temp!=-1)
                 cout<<"dequeued element is "<<temp<<endl;

             break;

      case 3:break;
      default : printf("invalid choice\n");

    }
  }while(choice!=3);
}
