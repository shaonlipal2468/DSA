#include <iostream>
using namespace std;
//https://www.geeksforgeeks.org/searching-array-adjacent-differ-k/

int search(int arr[], int n, int x, int k)
{
    int i=0;
    while(i<n)
    {
        if(arr[i]==x)
          return i;
        i = i+max(1,abs(arr[i]-x)/k);
    }
    return -1;
}

int main()
{
    int arr[] = {2, 4, 5, 7, 7, 6};
    int x = 6;
    int k = 2;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Element " << x  << " is present at index "
         << search(arr, n, x, k);
    return 0;

   return 0;
}
