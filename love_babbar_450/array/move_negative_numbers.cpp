//Here output e order is changing
#include<bits/stdc++.h>
using namespace std;
void printArray(int arr[],int n)
{
  for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";
  cout<<endl;
}
void rearrange_partition_method(int arr[],int n)
{
   int i = 0;
   for(int j=0;j<n;j++)
   {
     if(arr[j]<0)
     {
          if(i!=j)
          {
            swap(arr[i],arr[j]);
            i++;
          }
     }
   }
}

void two_pointer_method(int arr[],int n)
{
    int low=0;
    int high= n-1;
    while(low<=high)
    {
         if(arr[low]>0 && arr[high]<0)
         {
            swap(arr[low],arr[high]);
            low++;
            high--;
         }

         else if (arr[low]<0 && arr[high]<0)
            low++;
         else if (arr[low]>0 && arr[high]>0)
            high--;
         else if(arr[low]<0 && arr[high]>0)
         {
             low++;
             high--;
         }
    }
}

int main()
{
  int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
  int n = sizeof(arr) / sizeof(arr[0]);
  two_pointer_method(arr, n);
  printArray(arr, n);
}
