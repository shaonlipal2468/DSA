#include<iostream>
using namespace std;

void display(int *arr,int n)
{
  for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";
  cout<<endl;
}

void reverse_array(int *arr,int n)
{
  int i,j,temp;
  i=0;
  j=n-1;
  while(i<j)
  {
      temp=arr[i];
      arr[i]=arr[j];
      arr[j]=temp;
      i++;
      j--;
  }
}


int main()
{
  int t;
  cin>>t;
  while(t--)
  {
  int n;
  cin>>n;
  int *arr =(int *)malloc(n*sizeof(int));
  for(int i=0;i<n;i++)
     cin>>arr[i];
  reverse_array(arr,n);
  display(arr,n);
  }

}
