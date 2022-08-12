#include<iostream>
using namespace std;

void coin_change_combination(int arr[],int coin,int target)
{
  int size = target+1;
  int table[size]={0};

  table[0]=1;
  for(int i=0;i<coin;i++)
  {
    for(int j=arr[i];j<size;j++)
        table[j] +=table[j-arr[i]];
  }

 // for(int i=0;i<size;i++)
 //   cout<<table[i]<< " ";
 cout<<table[target]<<endl;
}



int main()
{
    int arr[] = {2,3,5};
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = 7;
    coin_change_combination(arr, m, n);
    return 0;
}
