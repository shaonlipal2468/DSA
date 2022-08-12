#include<iostream>
using namespace std;

struct answer{
  int max;
  int min;
};

struct answer tournament(int arr[],int start,int end)
{
   answer ans;
   if(start==end)  //only one element
       {
          ans.max=arr[start];
          ans.min=arr[start];
       }
   else if(start+1==end)  //only  2 elements
      {
                ans.max=max(arr[start],arr[end]);
                ans.min=min(arr[start],arr[end]);
      }
  else
      {
            int mid= start+ (end-start)/2;
            struct answer left = tournament(arr,start,mid);
            struct answer right = tournament(arr,mid+1,end);

            ans.max= max(left.max,right.max);
            ans.min= min(left.min,right.min);
     }
   return ans;
}
int main()
{
   int arr[]={1,2,33,5,-4};
   int n=sizeof(arr)/sizeof(arr[0]);
   //tournament method
   answer ans= tournament(arr,0,n-1);
   cout<<"Max element : "<<ans.max<<endl<<"Min element : "<<ans.min<<endl;
}
