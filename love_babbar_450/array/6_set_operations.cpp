#include<bits/stdc++.h>
using namespace std;

void union_opr(int a[],int n,int b[],int m)
{
	vector<int> union_array;
	int i=0,j=0;
	while(i<n && j<m)
	{
		if(a[i]<b[j])
		  {
		  	union_array.push_back(a[i]);
		  	i++;
		  }
		else if(a[i]>b[j])
		  {
		  	union_array.push_back(b[j]);
		  	j++;
     	}
     	else{
     		union_array.push_back(a[i]);
     		i++;
     		j++;
		 }		
	}
	
	for(int x=i;x<n;x++)
	   union_array.push_back(a[x]);
	for(int x=j;x<m;x++)
	   union_array.push_back(b[x]);
	   
	for(int x=0;x<union_array.size();x++)
	   cout<<union_array[x]<<" ";
	cout<<endl;
	
}

void intersection_opr(int a[],int n,int b[],int m)
{
	vector<int> intersection_array;
	int i=0,j=0;
	while(i<n && j<m)
	{
		if(a[i]<b[j])
		  	i++;
		else if(a[i]>b[j])
		  	j++;
     	else{
     		intersection_array.push_back(a[i]);
     		i++;
     		j++;
		 }		
	}

	for(int x=0;x<intersection_array.size();x++)
	   cout<<intersection_array[x]<<" ";
	cout<<endl;
	
}

void minus_opr(int a[],int n,int b[],int m)
{
	vector<int> minus_opr;
	int i=0,j=0;
	while(i<n && j<m)
	{
		if(a[i]<b[j])
		  {
		  	minus_opr.push_back(a[i]);
		  	i++;
		  }
		else if(a[i]>b[j])
		  j++;
     	
     	else{
     		i++;
     		j++;
		 }		
	}
	
	for(int x=i;x<n;x++)
	   minus_opr.push_back(a[x]);
	   
	for(int x=0;x<minus_opr.size();x++)
	   cout<<minus_opr[x]<<" ";
	cout<<endl;
	
}

int main()
{
   int arr1[]={1,2,7,9,10,11};
   int n=sizeof(arr1)/sizeof(arr1[0]);
   int arr2[]={2,4,6,8,10};
   int m=sizeof(arr2)/sizeof(arr2[0]);
   union_opr(arr1,n,arr2,m);
   intersection_opr(arr1,n,arr2,m);
   minus_opr(arr1,n,arr2,m);
}
