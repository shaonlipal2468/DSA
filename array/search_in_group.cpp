#include <iostream>

using namespace std;
//https://www.geeksforgeeks.org/check-if-a-key-is-present-in-every-segment-of-size-k-in-an-array/
int findxinkindowSize(int arr[],int x,int k,int n)
{
    int i,j;
    for(i=0;i<n;i=i+k)
    {
        for(j=i;j<i+k;j++)
        {
            if(arr[j]==x)
              break;
        }
        if(j==i+k)
          return false;
    }
    //if array size multiple of k , return true
    if(j==n)
      return true;
    //if array size is not multiple of k, search in last part of the array
    for(int p=j;p<n;p++)
    {
        if(arr[p]==x)
          return true;
    }
    return false;
}

int main()
{
    //int arr[] = { 3, 5, 2, 4, 9, 3, 1, 7, 3, 11, 12, 3 };
    int arr[]={3,1,1,1,3,1,3};
    int x = 3, k = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    if (findxinkindowSize(arr, x, k, n))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
