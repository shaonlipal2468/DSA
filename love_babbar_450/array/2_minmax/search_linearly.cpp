#include<iostream>
using namespace std;

struct answer{
  int max;
  int min;
};

struct answer getminmax(int arr[],int n)
{
   int max=arr[0],min=arr[0];
   for(int i=1;i<n;i++)
   {
       if(arr[i]>max)
            max=arr[i];
       else if(arr[i]<min)
            min = arr[i];
   }
   
   answer ans;
   ans.max=max;
   ans.min=min;
   return ans;
}
   

int main()
{
   int arr[]={1,2,3,4,5};
   int n=sizeof(arr)/sizeof(arr[0]);
   //linearly searching method
   answer ans1= getminmax(arr,n);
   cout<<ans1.max<<" "<<ans1.min<<endl;

   
}
