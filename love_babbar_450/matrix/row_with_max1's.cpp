#include<bits/stdc++.h>
using namespace std;
int find_one(vector<int> arr)
   {
       int count=0;
       for(int i=0;i<arr.size();i++)
       {
           if(arr[i]==1)
           count++;
       }
       return count;
   }
   int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
 	    // code here
 	    int max_row_index=-1;
 	    int count_one_global=0;
 	    for(int i=0;i<n;i++)
 	    {
 	        int count=find_one(arr[i]);
 	        if(count>count_one_global)
             {
              count_one_global=count;
              max_row_index=i;
             }
 	    }
 	    return max_row_index;

 	}
 int main()
 {
   //vector<vector<int>> arr{{0,1,1,1},{0,0,1,1},{1,1,1,1},{0,0,0,0}};
   vector<vector<int>> arr{{0,0},{0,0}};
   int n=2,m=2;
   cout<<rowWithMax1s(arr,n,m)<<endl;
 }
