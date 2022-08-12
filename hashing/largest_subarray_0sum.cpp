//https://www.youtube.com/watch?v=C9-n_H7dsvU
#include<bits/stdc++.h>
using namespace std;
int largest_subarray_0sum(int arr[],int n)
{
  unordered_map<int, int> prefix_sum;
  int sum = 0;
  int max_len = 0;
  for (int i = 0; i < n; i++) {
      sum += arr[i];
      if (arr[i] == 0 && max_len == 0)
          max_len = 1;
      if (sum == 0)
          max_len = i + 1;
      if (prefix_sum.find(sum) != prefix_sum.end())
          max_len = max(max_len, i - prefix_sum[sum]);
      else
          prefix_sum[sum] = i;
  }
  return max_len;
}
int main()
{
 //int arr[]={2,8,-3,-5,2,-4,6,1,2,1,-3,4};
    int arr[]={-375, -935, 446, -178, -886, -347, -658, 337, -341, 207 ,714, -320,
                820, 722, -938, 941, 706, -126, -983 ,-919, -421, 397, 631, -291,
                -671, -624, 223, 641, -897, 299, -523, -208 ,820 ,-731, 995, -378,
                274, -849, 861, -578, -992, 622, 505, 962 ,-325, 945, -201, -783,
                843 ,-527, 873, -957, -35, -752, -302, 134, -889, -566, -367,
                501, -787, 250, -302, 364, 254 ,-685, 153, -974 ,-156, 437, -413,
                461, -27, 51, -555, -793, 700, 40, -427, 501, 648, -158, 536, -338,
                -214 ,505 ,50, -284, 344 ,178, -237};
                int sum=0;
    int n =sizeof(arr)/sizeof(arr[0]);
    cout<<largest_subarray_0sum(arr,n);
}
