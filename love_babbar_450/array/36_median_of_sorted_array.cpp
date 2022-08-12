#include <bits/stdc++.h>
using namespace std;
double median(int *arr1,int n1,int *arr2,int n2)
{
    int *temp,flag;
    if(n1>n2) //n1 will contain the smaller array
    {
        temp=arr1;
        arr1=arr2;
        arr2=temp;
        
        flag=n1;
        n1=n2;
        n2=flag;
    }
    
    int low=0;
    int high=n1;
    int cut1,cut2,l1,l2,r1,r2;
    
    while(low<=high)
    {
        cut1=(low+high)/2;
        cut2=(n1+n2)/2 - cut1;
        
        l1= cut1==0? INT_MIN : arr1[cut1-1];
        l2= cut2==0? INT_MIN : arr2[cut2-1];
        
        r1=cut1==n1?INT_MAX:arr1[cut1];
        r2=cut2==n2?INT_MAX:arr2[cut2];
        
        
        if(l1>r2)
            high=cut1-1;
        else if(l2>r1)
            low=cut1+1;
        else{
            return (n1+n2)%2 == 0 ? 
            (max(l1,l2)+min(r1,r2))*1.0/2.0 : min(r1,r2);
            cout<<ans<<endl;
            
        }
    }
}

int main()
{
   int arr1[]={1,5,8,10,18,20};
   int arr2[]={2,3,6,7};
   
   int n= sizeof(arr1)/sizeof(arr1[0]);
   int m= sizeof(arr2)/sizeof(arr2[0]);
   
   cout<<median(arr1,n,arr2,m);
   
   return 0;
}

