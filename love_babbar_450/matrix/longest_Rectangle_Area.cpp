#include<bits/stdc++.h>
#include "myfile.h"
using namespace std;

int max(int a,int b)
    {
        return a>b?a:b;
    }
    int longestRectangleArea(int arr[],int n) {
      int right_boundary[n];
       //store next smaller element index on the left
      stack<int> s;
      s.push(n-1);
      right_boundary[n-1]=n;
      for(int i=n-2;i>=0;i--)
      {
        while(s.size()>0 && arr[i]<= arr[s.top()])
           s.pop();
        if(s.size()==0)
           right_boundary[i]= n;
        else
           right_boundary[i]=s.top();
        s.push(i);
      }


      int left_boundary[n];
      stack<int> s2;
      s2.push(0);
      left_boundary[0]=-1;
      for(int i=1;i<n;i++)
      {
        while(s2.size()>0 && arr[i]<= arr[s2.top()])
           s2.pop();
        if(s2.size()==0)
           left_boundary[i]= -1;
        else
           left_boundary[i]=s2.top();
        s2.push(i);
      }


       //area calculation
       long long maxArea=0;
       for(int i=0;i<n;i++)
       {
         int width = right_boundary[i]-left_boundary[i]-1;
         int area = arr[i]*width;
         maxArea= max(maxArea,area);
       }
       return maxArea;
    }

int main()
{
  int histogram[]={1,1};
  int n = sizeof(histogram)/sizeof(histogram[0]);
  cout<<largestRectangleArea(histogram,n);
}
