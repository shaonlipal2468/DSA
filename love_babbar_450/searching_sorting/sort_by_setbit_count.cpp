#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
      static int setBits(int N) {
        // Write Your Code here
        //kernighan's algo
        int counter =0;
        while(N>0)
        {
             int right_set_bit_mask = N&-N;
             N-=right_set_bit_mask;
             counter++;
        }
        return counter;
    }

    static bool comparator(int a,int b)
    {
        return setBits(a)>setBits(b);
    }
    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
        stable_sort(arr,arr+n,comparator);

    }

};

// { Driver Code Starts.
//1
//3
// 3,1,5
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
