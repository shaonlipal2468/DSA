#include <bits/stdc++.h>
using namespace std;
void print_array(int arr[],int n)
{
  for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
  cout<<endl;
}

vector<int> findDuplicates(int arr[], int n) {
       // code here
         vector<int> ans;
       for (int i = 0; i < n; i++)
           {
              int index = arr[i] % n;
              arr[index] += n;
           }

       for (int i = 0; i < n; i++)
           {
             cout<<arr[i] / (n*1.0)<<" "<<arr[i]<<endl;
             if (arr[i] / n > 1)
                 ans.push_back(i);
           }
       if(!ans.size())
           ans.push_back(-1);
      print_array(arr,5);
       return ans;
   }

   int main()
   {
     int nums[] = {2,3,1,2,3};
     vector<int> ans =findDuplicates(nums,5);

     for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
     cout<<endl;

   }
