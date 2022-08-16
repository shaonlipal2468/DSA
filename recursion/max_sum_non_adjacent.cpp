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
void fun(int index,vector<int> arr,vector<int> &output,bool flag,int sum_of_elements,int &max_sum)
{
    if(index>=arr.size())
    {
        if(max_sum<sum_of_elements)
            max_sum = sum_of_elements;
        print(output);
        return;
    }
    
    if(flag==false)
    {
			 output.push_back(arr[index]);
			 fun(index+1,arr,output,true,sum_of_elements+arr[index],max_sum);
			 output.pop_back();
			 fun(index+1,arr,output,false,sum_of_elements,max_sum);
    }
    else if(flag==true)
    		 fun(index+1,arr,output,false,sum_of_elements,max_sum);
       
}
/*
//if you dont want to print those subsequences 
void fun(int index,vector<int> arr,bool flag,int sum_of_elements,int &max_sum)
{
    if(index>=arr.size())
    {
        if(max_sum<sum_of_elements)
            max_sum = sum_of_elements;
        return;
    }
    
    if(flag==false)
    {
			 fun(index+1,arr,true,sum_of_elements+arr[index],max_sum);
			 fun(index+1,arr,false,sum_of_elements,max_sum);
    }
    else if(flag==true)
    		 fun(index+1,arr,false,sum_of_elements,max_sum);
       
}
*/


int main()
{
   vector<int> arr ={5,10,10,100,5,6};
   vector<int> output;
   int sum_of_elements=0;
   int max_sum = INT_MIN;
   fun(0,arr,output,false,sum_of_elements,max_sum);
   //if you dont want to print those subsequences 
   //fun(0,arr,false,sum_of_elements,max_sum);
   cout<<max_sum<<endl;
   return 0;
}
