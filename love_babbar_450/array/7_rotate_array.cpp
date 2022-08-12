#include<iostream>
using namespace std;

void display(int *arr,int n)
{
  for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";
  cout<<endl;
}

void rotate(int arr[], int n)
{
    int temp=arr[n-1];
    int y,z;
    y=arr[0];

    for(int i=0;i<n-1;i++)
    {
        z=arr[i+1];
        arr[i+1]=y;
        y=z;
    }
    arr[0]=temp;
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
  rotate(arr,n);
  display(arr,n);
  }

}
