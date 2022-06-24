/* Online C++ Compiler and Editor */
#include <bits/stdc++.h>
using namespace std;
void print(vector<int> arr)
{
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void fun(int index,vector<int> arr,vector<int> &output,int sum,int k)
{
    if(index>=arr.size())
    {
        if(sum==k)
           print(output);
        return;
    }
    
    output.push_back(arr[index]);
    fun(index+1,arr,output,sum+arr[index],k);
    output.pop_back();
    fun(index+1,arr,output,sum,k);
    
}
int main()
{
   vector<int> arr ={1,2,1};
   vector<int> output;
   int sum =0;
   int k=2;
   fun(0,arr,output,sum,k);
   cout<<"Done"<<endl;
   return 0;
}
