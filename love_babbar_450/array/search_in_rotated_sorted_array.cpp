#include<bits/stdc++.h>
using namespace std;
int search(int arr[], int low, int high, int key){
  //complete the function here
      if(low>high)
       return -1;

      int mid =  low+(high-low)/2;
      if(key==arr[mid])
         return mid;

      else if(arr[low]<=arr[mid])   //first half is sorted
      {
          if(key>=arr[low] && key<=arr[mid])
             return search(arr,low,mid-1,key);
          else
             return search(arr,mid+1,high,key);

      }
      else //second half is sorted
      {
          if(key>=arr[mid] && key<=arr[high])
             return search(arr,mid+1,high,key);
          else
             return search(arr,low,mid-1,key);

      }

  }

  int main()
  {
  int nums[] = {4,5,6,7,0,1,2};
  int target = 0;
  int n= sizeof(nums)/sizeof(nums[0]);
  cout<<search(nums,0,n-1,target);
  }
