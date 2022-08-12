#include<iostream>
using namespace std;


void print(int arr[],int n)
{
   for(int i=0;i<n;i++)
       cout<<arr[i]<<" ";
   cout<<endl;
}

void reverse_array(int arr[],int start,int end)
{
   while(start<end)
     {
         int temp=arr[start];
         arr[start]=arr[end];
         arr[end]=temp;
         start++;
         end--;
     }
}

void recur_rev_array(int arr[],int start,int end)
{
    if(start>=end)
       return;
    
    int temp=arr[start];
    arr[start]=arr[end];
    arr[end]=temp;
    recur_rev_array(arr,start+1,end-1);
}   
   

int main()
{
   int arr[]={1,2,3,4,5};
   int n=sizeof(arr)/sizeof(arr[0]);
   reverse_array(arr,0,n-1);
   print(arr,n);
   
   recur_rev_array(arr,0,n-1);
   print(arr,n);
   
}
