#include<iostream>
#include"header.h"
using namespace std;
template<typename T>
Stack<T>::Stack(){
   capacity=100;
   top=-1;
   arr = new T[capacity];
}
template<typename T>
void Stack<T>::push(T data)
{
  if(!isFull())
    arr[++top]=data;
  else
    cout<<"Overflow"<<endl;
}

template<typename T>
T Stack<T>::pop()
{
  if(!isEmpty())
     return arr[top--];
  else
  {
    cout<<"Underflow"<<endl;
  }
}

template<typename T>
bool Stack<T>:: isEmpty()
{
  return top==-1;
}

template<typename T>
bool Stack<T>:: isFull()
{
  return top+1==capacity;
}
template<typename T>
int Stack<T>::show_top()
{
  if(top!=-1)
    return arr[top];
  else
    return -999;
}

template<typename T>
void Stack<T>::show_stack()
{
  for(int i=0;i<=top;i++)
     cout<<arr[i]<<" ";
  cout<<endl;
}

template<typename T>
Queue<T>::Queue(){
   capacity=100;
   front = rear = -1;
   size=0;
   arr = new T[capacity];
}

template<typename T>
bool Queue<T>:: isFull()
{
  if(((rear+1)%capacity)==front)
    return true;
  return false;
}
template<typename T>
bool Queue<T>:: isEmpty()
{
  if(rear==-1 && front==-1)
    return true;
  return false;
}


template<typename T>
void Queue<T> :: enQueue(T data)
{
  if(isFull())
    printf("Overflow\n");
  if(front ==-1 && rear ==-1)
        front = rear=0;
  else
        rear = (rear+1)%capacity;
  arr[rear]=data;
  size++;
}
template<typename T>
T Queue<T>:: deQueue()
{
  if(isEmpty())
    {
      printf("underflow\n");

    }
  else
  {
    T temp = arr[front];
    if(front==rear)
       front=rear =-1;
    else
       front = (front+1)%capacity;
    size--;
    return temp;
  }

}
template<typename T>
int Queue<T>::size_()
{
  return size;
}
