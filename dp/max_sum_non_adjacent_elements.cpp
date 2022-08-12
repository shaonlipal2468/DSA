#include <iostream>
using namespace std;

//https://www.youtube.com/watch?v=VT4bZV24QNo

int FindMaxSum(int arr[], int n)
{
    // Your code here
    int old_inclusion = arr[0];
    int old_exclusion =0;

    for(int i=1;i<n;i++)
    {
        int new_inclusion = old_exclusion+ arr[i];
        int new_exclusion = max(old_inclusion,old_exclusion);

        old_inclusion=new_inclusion;
        old_exclusion=new_exclusion;
    }
    return max(old_inclusion,old_exclusion);
}

int main()
{
   int arr[] = {5,5,10,100,10,5};
   int n =sizeof(arr)/sizeof(arr[0]);
   cout<<FindMaxSum(arr,n);
}
