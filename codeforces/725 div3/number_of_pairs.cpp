#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
   ll t;
   cin>>t;
   while(t--)
   {
       ll n,l,r,temp;
       cin>>n>>l>>r;
       vector<ll> arr;
       for(ll i=0;i<n;i++)
       {
         cin>>temp;
         arr.push_back(temp);
       }

       sort(arr.begin(),arr.end());

       ll dis1,dis2,up,lw,a,b,ans=0;
       for(int i=0;i<n;i++)
       {
          a = l-arr[i];
          auto lw = lower_bound(arr.begin(),arr.end(),a);
          dis1 = distance(arr.begin(),lw);
          if(dis1<=i)
            dis1=i+1;

            b = r-arr[i];
            auto up = upper_bound(arr.begin(),arr.end(),b);
            dis2 = distance(arr.begin(),up);
            if(dis2<=i)
              dis2=i+1;
           ans+=dis2-dis1;

       }
       cout<<ans<<endl;


   }
}
