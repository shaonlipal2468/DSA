#include<bits/stdc++.h>
using namespace std;


vector<int> threeWayPartition(vector<int>& arr,int a, int b)
   {
       // code here
   int low =0;
   int mid=0;
   int high = arr.size()-1;

   while(mid<=high)
   {
       if(arr[mid]<a)
          {
              swap(arr[mid],arr[low]);
              low++;mid++;
          }
       else if(arr[mid]>b)
          {
              swap(arr[mid],arr[high]);
              high--;
          }
       else mid++;
   }
   return arr;
   }


   int main()
  {
     vector<int> arr = {1,2,3,3,4,5,8,2,1,9};

     //ans coming  1 1       3 3 4 5 2 2      9 8
//             less than 2   2<= x <= 5      more than 5
//order in the segments does not matter

     int a= 2;
     int b= 5;
     vector<int> ans = threeWayPartition(arr,a,b);
     for(int i=0;i<ans.size();i++)
           cout<<arr[i]<<" ";
     cout<<endl;

  }
