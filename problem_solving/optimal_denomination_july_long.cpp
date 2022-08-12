#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll gcd(ll a,ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

ll util(ll arr[],ll mid[],int n)
{
  unordered_map<ll,set<ll>> m;
  for(int i=0;i<n;i++)
       m[mid[i]].insert(arr[i]);
  ll denomination = *max_element(mid,mid+n);
  auto it = m[denomination].end();
  it--;
  ll flag = *it;

  ll ans =1;
  bool done =false;
  for(ll i=0;i<n;i++)
  {
    if(done == false && arr[i]==flag)
    {
      done = true;
        continue;
    }
    ans+=arr[i]/denomination;
  }
  return ans;


}


ll solve(ll arr[],ll n)
 {
    ll left[n],right[n],mid[n];
    left[0]=0;
    right[n-1]=0;

    for(ll i=1;i<n;i++)
       left[i]=gcd(arr[i-1],left[i-1]);
    for(ll i=n-2;i>=0;i--)
       right[i]=gcd(arr[i+1],right[i+1]);
    for(ll i=0;i<n;i++)
       mid[i] = gcd(left[i],right[i]);
    return util(arr,mid,n);



}


int main() {
	ll t,n;
	cin>>t;
	while(t--)
	{
	     cin>>n;
	     ll arr[n];
	     for(ll i=0;i<n;i++)
	       cin>>arr[i];
	     cout<<solve(arr,n)<<endl;

	}
	return 0;
}
