#include<bits/stdc++.h>
using namespace std;
#define n 100
int top =-1;

void push(int arr[],int data)
{
  if(top>=n-1)
     {
       cout<<"overflow"<<endl;
       return;
     }
  arr[++top]=data;

}

int pop(int arr[])
{
  if(top<0)
  {
    cout<<"underflow"<<endl;
    return -1;
  }

  return arr[top--];
}

void display(int arr[])
{
  for(int i=top;i>=0;i--)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int main(){
  int choice,data;
  int arr[n];

  do
  {
    cout<<"1. push"<<endl;
    cout<<"2. pop"<<endl;
    cout<<"3. display"<<endl;
    cout<<"4. Exit"<<endl;

    cout<<endl<<"enter ur choice"<<endl;
    cin>>choice;

    switch (choice) {
      case 1:cout<<"enter data"<<endl;
             cin>>data;
             push(arr,data);
             break;


      case 2:cout<<"Popped element is "<<pop(arr)<<endl;
             break;

      case 3:display(arr);
             break;

      case 4:break;
      default : cout<<"invalid choice"<<endl;

    }
  }while(choice!=4);
}
