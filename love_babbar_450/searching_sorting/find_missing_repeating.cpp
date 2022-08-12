/*
Given an unsorted array Arr of size N of positive integers.
One number 'A' from set {1, 2, …N} is missing and one number
'B' occurs twice in array. Find these two numbers.
*/
#include <bits/stdc++.h>
using namespace std;

int *findTwoElement(int *arr, int n) {
    // code here
    int *ans = new int[2];
    for(int i=0;i<n;i++)
    {
        int index= abs(arr[i])-1;
        if(arr[index] <0)
            ans[0]=abs(arr[i]);
        else
        arr[index] = -arr[index];

    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]>0)
        {
          ans[1]=i+1;
          break;
        }
    }
    return ans;
}

int main()
{
  int arr[]={1,3,3};
  int n=3;
  int *p= findTwoElement(arr,n);
  cout<<"Repeating is "<<p[0]<<endl<<"Missing is "<<p[1]<<endl;
}
