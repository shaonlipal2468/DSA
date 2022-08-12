#include<bits/stdc++.h>
using namespace std;

int solve(int n)
{
  if(n<=6)
    return n;

    int arr[n];
    for (int i = 1; i <= 6; i++)
  		arr[i - 1] = i;

  	for (int i= 7; i <= n; i++) {
  		arr[i - 1] = 0;

  		for (int j = n - 3; j >= 1; j--) {

  			int curr = (i - j - 1) * arr[j - 1];
  			if (curr > arr[i - 1])
  				arr[i - 1] = curr;
  		}
  	}
  	


  for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";
  cout<<endl;
  return arr[n-1];
}

int main()
{
  int n=11;
  cout<<solve(n)<<endl;
}
