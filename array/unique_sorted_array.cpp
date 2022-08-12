/*
Given a sorted array nums, remove the duplicates in-place
such that each element appears only once and returns the new length.
Do not allocate extra space for another array, you must do this by
modifying the input array in-place with O(1) extra memory.
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> removeDuplicates(vector<int> arr) {
        int length=arr.size();
        if(length==0)
           return arr;
        int index=0; //next index+1 position e item place hbe
        int last=arr[0];  //last unique element
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]!=last)
            {
                arr[++index]=arr[i];
                last=arr[i];
            }
        }
        for(int i=index+1;i<length;i++)
           arr.pop_back();
        return arr;

    }
int main()
{
vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
nums=removeDuplicates(nums);
cout<<nums.size();

}
