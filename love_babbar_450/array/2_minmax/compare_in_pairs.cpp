#include<iostream>
using namespace std;

struct answer{
  int max;
  int min;
};
  
struct answer compare_pairs(int arr[],int n)
{
   answer ans;
   int i;
   
   if(n%2!=0)  //n is odd
   {
     ans.max=arr[0];
     ans.min=arr[0];
     i=1;
   }
   
   else  // n is even
   {
      if(arr[0]<arr[1])
         {
            ans.max= arr[1];
            ans.min= arr[0];
         }
      else
         {
            ans.max= arr[0];
            ans.min= arr[1];
         }
      i=2;
    }
    
    while(i<n)
    {
        if(arr[i]<arr[i+1])
           {
               if(arr[i]<ans.min)
                     ans.min=arr[i];
               if(arr[i+1]>ans.max)
                     ans.max=arr[i+1];
           }
         else
           {
                if(arr[i+1]<ans.min)
                     ans.min=arr[i+1];
               if(arr[i]>ans.max)
                     ans.max=arr[i];
           }
         i=i+2;
     }
    return ans;
}         
    

int main()
{
   int arr[]={1,2,3,4,5};
   int n=sizeof(arr)/sizeof(arr[0]);
  
    //compare in pairs
   answer ans3= compare_pairs(arr,n);
   cout<<ans3.max<<" "<<ans3.min<<endl;
   
   
   
}
