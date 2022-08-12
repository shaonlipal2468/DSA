#include<iostream>
#include<string>
using namespace std;

char int_to_char(int n)
{
   if(n==0)
     return '0';
    else if (n==1)
     return '1';
    else if (n==2)
     return '2';
    else if (n==3)
     return '3';
    else if (n==4)
     return '4';
    else if (n==5)
     return '5';
    else if (n==6)
     return '6';
    else if (n==7)
     return '7';
    else if (n==8)
     return '8';
    else
      return '9';
}


/*Complete the function below*/
int check_number(int n)
{
    string number;
    while(n>0)
    {
        number.push_back(int_to_char(n%10));
        n=n/10;
    }
    int low=0;int high= number.size()-1;

    while(low<=high)
    {
        if(number[low]!=number[high])
           return 0;
        low++;
        high--;
    }
    return 1;
}
int PalinArray(int a[], int n)
{  //add code here.
   for(int i=0;i<n;i++)
   {
       if(!check_number(a[i]))
          return 0;
   }
   return 1;
}
int main()
{
  int arr[] = {111, 222, 333, 444, 555};
  int n= sizeof(arr)/sizeof(arr[0]);
  cout<<PalinArray(arr,n);
}
