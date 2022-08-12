#include<bits/stdc++.h>
using namespace std;

void display(int *arr,int n)
{
  for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";
  cout<<endl;
}

void dutch_flag(int *arr,int n)
{
   int low=0;
   int high=n-1;
   int mid=0;

    while(mid<=high)
   {
      switch(arr[mid])
      {
        case 0:
                swap(arr[low],arr[mid]);
                low++;
                mid++;
                break;
        case 1:
                mid++;
                break;
        case 2:
                swap(arr[mid],arr[high]);
                high--;
                //mid++;If we do this,solution will be wrong,
                //as we don't know what will come after swapping
                break;
      }
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
  dutch_flag(arr,n);
  display(arr,n);
  }

}
