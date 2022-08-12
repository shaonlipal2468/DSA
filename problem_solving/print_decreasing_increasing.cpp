//print n -> n-1 -> n-2 ......1->1->2 ->3 ->4....->n
#include <iostream>
using namespace std;
void solve(int temp,bool flag,int n)
{
    cout<<temp<<endl;
    if(flag==false)
       {
           if(temp==1)
           {
               flag=true;
               solve(temp,flag,n);
           }
          else
            solve(temp-1,flag,n);
       }
    else
    {
        if(temp==n)
               return;
        else
            solve(temp+1,flag,n);
    }
}


int main()
{
   int n=10,temp;
   temp=n;
   solve(temp,false,n);
   return 0;
}
