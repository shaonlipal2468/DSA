#include<bits/stdc++.h>
using namespace std;

void util(int sum[],int n)
{
  int pos=0;
   while(n)
   {
       if(n&1)
            sum[pos]++;
        pos++;
        n=n>>1;
   }
}

int solve(int arr[],int n,int k)
{
    int sum[32],i,j,ans=0;
    for(i=0;i<32;i++)
      sum[i]=0;
    for(i=0;i<n;i++)
        util(sum,arr[i]);
    // for(i=0;i<32;i++)
    //    cout<<sum[i]<<" ";
    // cout<<endl;

    for(i=0;i<32;i++)
    {
        if(sum[i]%k==0)
           ans+=sum[i]/k;
        else
           ans+=(sum[i]/k)+1;
    }
    return ans;

}

int main()
{
   int t,n,i,k;
   cin>>t;
   while(t--)
   {
       cin>>n>>k;
       int arr[n];
       for(i=0;i<n;i++)
          cin>>arr[i];
       cout<<solve(arr,n,k)<<endl;
   }

   return 0;
}
