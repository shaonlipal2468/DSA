#include<bits/stdc++.h>
using namespace std;
//using priority queue(min heap)
//always take out the min element and negate it and again push into the min heap

int maximizeSum_minheap(int a[], int n, int k)
    {
        int sum =0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i=0;i<n;i++)
            pq.push(a[i]);

        while(k--)
        {
          int temp = pq.top();
          pq.pop();
          temp = (temp) * -1;
          pq.push(temp);
        }

        while (!pq.empty())
        {
           sum = sum + pq.top();
           pq.pop();
        }
  return sum;
}

//this method modifiy the original array
int maximizeSum(int a[], int n, int k)
    {
        // Your code goes here
        sort(a,a+n);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]<0 && k>0)
            {
                a[i]=-a[i];
                k--;
            }
        }
        for(int i=0;i<n;i++)
          sum+=a[i];

        //find min element
        int min_ele=a[0];
        for(int i=0;i<n;i++)
           min_ele = min(min_ele,a[i]);

        if(k%2!=0)//odd number
          sum =sum-2*min_ele;
        return sum;
    }
int main()
{
    int arr[] = {5, -2, 5, -4, 5, -12, 5, 5, 5, 20};

    /*
    Here  we have k=5 so we turn -2, -4, -12 to
    2, 4, and 12 respectively. Since we have
    performed 3 operations so k is now 2. To get
    maximum sum of array we can turn positive
    turned 2 into negative and then positive
    again so k is 0. Now sum is
    5+5+4+5+12+5+5+5+20+2 = 68

    */
    int k=5;
    int n= sizeof(arr)/sizeof(arr[0]);
    cout<<maximizeSum_minheap(arr,n,k)<<endl;
    cout<<maximizeSum(arr,n,k)<<endl;

}
