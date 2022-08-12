#include<bits/stdc++.h>
using namespace std;
void printArray(int arr[],int n)
{
  for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";
  cout<<endl;
}

//insertion sort method
void move_negative(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
       if(arr[i]<0)
       {
          int temp = arr[i],j;
          for( j=i-1;j>=0 && arr[j]>0;j--)
                 arr[j+1]=arr[j];
          arr[j+1]=temp;
       }
    }
}

//Optimized merge sort - Divide and conquer
void reverse(int arr[], int l, int r)
{
    while (l < r) {
        swap(arr[l], arr[r]);
        l++;
        r--;
    }
}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i = l; // Initial index of 1st subarray
    int j = m + 1; // Initial index of IInd

    while (i <= m && arr[i] < 0)
        i++;

    // arr[i..m] is positive

    while (j <= r && arr[j] < 0)
        j++;

    // arr[j..r] is positive

    // reverse positive part of
    // left sub-array (arr[i..m])
    reverse(arr, i, m);

    // reverse negative part of
    // right sub-array (arr[m+1..j-1])
    reverse(arr, m + 1, j - 1);

    // reverse arr[i..j-1]
    reverse(arr, i, j - 1);
}

// Function to Rearrange positive and negative
// numbers in a array
void RearrangePosNeg(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        RearrangePosNeg(arr, l, m);
        RearrangePosNeg(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
int main()
{
  int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  printArray(arr, n);
  RearrangePosNeg(arr, 0,n-1);
  printArray(arr, n);
}
