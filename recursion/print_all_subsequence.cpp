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
void fun(int index,vector<int> arr,vector<int> &output)
{
    if(index>=arr.size())
    {
        print(output);
        return;
    }
    output.push_back(arr[index]);
    fun(index+1,arr,output);
    output.pop_back();
    fun(index+1,arr,output);
    
}


int main()
{
   vector<int> arr ={3,1,2};
   vector<int> output;
   fun(0,arr,output);
   cout<<"Done"<<endl;
   return 0;
}
