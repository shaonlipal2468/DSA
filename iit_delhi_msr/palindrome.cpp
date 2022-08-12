//https://www.geeksforgeeks.org/count-of-sub-arrays-whose-elements-can-be-re-arranged-to-form-palindromes/
#include<bits/stdc++.h>
using namespace std;
void print_ans(vector<pair<int,int>> ans,int arr[])
{
  for(auto x:ans)
  {
    cout<<x.first<<" "<<x.second<<"........";
    for(int pos=x.first;pos<=x.second;pos++)
       cout<<arr[pos]<<" ";
    cout<<endl;
  }
}
bool util(unordered_map<int,int> m)
{
    for(auto x: m)
    {
       if(x.second!=2)
         return false;
    }
    return true;
}
bool util2(unordered_map<int,int> m)
{
   bool flag_1= false,flag_3=false;
   for(auto x:m)
   {
       if(x.second>3)
            return false;
       else if(x.second==1 )
       {
           if(!flag_1)
                flag_1= true;
           else
                return false;
     }

     else if(x.second == 3)
     {
          if(!flag_3)
                flag_3= true;
          else
                return false;
     }
   }
   return true;
}
void store_occurence(unordered_map<int,int> & m,int i,int j,int arr[])
{
  if(j==i+1)
  {
    m.clear();
    for(int k=i;k<=j;k++)
        m[arr[k]]++;
  }
  else
     m[arr[j]]++;
}
void count_palindrome(int arr[],int n,vector<pair<int,int>> &ans)
{

  unordered_map<int,int> m;
  for(int i=0;i<n;i++)
  {
     for(int j=i+1;j<n;j++)
     {
        store_occurence(m,i,j,arr);
        if((j-i+1)%2==0 && util(m))  //if length of subarray is even ..check every element occurs 2 times
          ans.push_back({i,j});

        //if length of subarray is odd --count 1 or 3 can be there exactly once
        //rest of elements occurence will be 2
        else if((j-i+1)%2!=0 && util2(m))
          ans.push_back({i,j});
     }
  }
}
int main()
{
    int arr[]={9,4,1,9,4,1,1,9,9,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<pair<int,int>> ans;
    count_palindrome(arr,n,ans);
    print_ans(ans,arr);
}
