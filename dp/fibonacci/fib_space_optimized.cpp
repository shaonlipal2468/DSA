#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int prev2 = 0;
    int prev1 = 1;
    
    for(int i=2;i<=n;i++)
    {
        int curr= prev1+prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    if(n==0)
        cout<<prev2<<endl;
    else
        cout<<prev1<<endl;
}
