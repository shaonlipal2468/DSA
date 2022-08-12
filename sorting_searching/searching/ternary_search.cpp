#include<bits/stdc++.h>
using namespace std;

int ternary_Search(int arr[],int n,int search)
{
  int low =0;
  int high = n-1;
  while(low<=high)
  {
      int mid1= low+(high-low)/3;
      int mid2= mid1+(high-low)/3;

      if(arr[mid1]==search) //first comparison
         return mid1;
      else if(arr[mid2]==search) //second comparison
         return mid2;
      else if(arr[mid1]>search)  //third comparison
         high=mid1-1;
      else if(search>arr[mid2])  //fourth comparison  (atmost 4 comparisons in each iteration)
         low=mid2+1;
      else
         {
            low =mid1+1;
            high=mid2-1;
         }
  }
  return -1;
}

int main()
{
  int arr[]={1,2,4,5,8,9,10,14,19};
  int n= sizeof(arr)/sizeof(arr[0]);
  int search=19;
  cout<<ternary_Search(arr,n,search);


}
