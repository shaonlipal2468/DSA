#include<bits/stdc++.h>
using namespace std;

//formula (2n)C(n) / (n+1)

unsigned long int catalan(unsigned int n)
{
 if(n<=1)
   return 1;

  unsigned long int res=0;

  for(int i=0;i<n;i++)
    res = res+catalan(i)*catalan(n-i-1);
  return res;
}
unsigned long int bionomial(unsigned int n,unsigned int k)
{
  if(k>n-k)
    k=n-k;
  unsigned long int res=1;
  for(int i=0;i<k;i++)
     {
       res = res*(n-i);
       res=res/(i+1);
     }
     return res;

}
unsigned long int catalan_formula(unsigned int n)
{
  unsigned long int c= bionomial(2*n,n)/(n+1);
  return c;
}

int main()
{
  unsigned int n;
  cin>>n;
  //cout << catalan(n-1) << endl;
  for(int i=0;i<n;i++)
        cout<< catalan_formula(i)<<" ";
  cout<<endl;
  return 0;
}
