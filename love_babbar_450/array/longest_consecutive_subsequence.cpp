#include<bits/stdc++.h>
using namespace std;
int findLongestConseqSubseq(int arr[], int n)
{
  //Your code here
  unordered_map<int,bool> m;
  for(int i=0;i<n;i++)
     m[arr[i]]=true;

  for(int i=0;i<n;i++)
      if(m.find(arr[i]-1)!=m.end()) //found
         m[arr[i]]=false;

  int length=INT_MIN;
  for(int i=0;i<n;i++)
  {
      if(m[arr[i]])
      {
          int count=1;
          int val=arr[i]+1;
          while(1)
          {
              if(m.find(val)!=m.end())
              {
                  count++;
                  val++;
              }
              else
                {
                    length=max(length,count);
                    break;
                }
          }
      }
  }
  return length;
}
int main()
{
   int arr[]={2,6,1,9,4,5,3};
   int n= sizeof(arr)/sizeof(arr[0]);
   cout<<findLongestConseqSubseq(arr,n);
}
