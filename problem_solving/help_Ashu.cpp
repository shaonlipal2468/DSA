//Help Ashu - Using Segment tree
#include<bits/stdc++.h>
using namespace std;
 //pair : even,odd
int getMid(int a,int b)
{
  return a+(b-a)/2;
}
pair<int,int> constructUtil(int arr[],int ss,int se,pair<int,int> *st,int si)
{
  if(ss==se)
  {
     if(arr[ss]&1) //odd : 0,1
        st[si] = {0,1};
     else
        st[si] = {1,0};
  }
  else
  {
    int mid = getMid(ss,se);
    pair<int,int> left = constructUtil(arr, ss, mid, st, si*2+1);
    pair<int,int> right = constructUtil(arr, mid+1, se, st, si*2+2);

    st[si].first = left.first+right.first;
    st[si].second = left.second+right.second;
  }
  return st[si];
}

pair<int,int> *construct_tree(int arr[],int n)
{
  int  x = (int)(ceil(log2(n)));
  int max_size = (int)pow(2,x+1)-1;
  pair<int,int> *st = new pair<int,int>[max_size];
  constructUtil(arr,0,n-1,st,0);
  return st;
}

pair<int,int> get_count(int arr[],int ss,int se,int qs,int qe,pair<int,int> *st,int si)
{
    if(qs>se || ss>qe) //completely outside
       return {0,0};
    if(qs<=ss && qe>=se)
       return st[si];
    int mid = getMid(ss,se);
    pair<int,int> left = get_count(arr,ss,mid,qs,qe,st,2*si+1);
    pair<int,int> right = get_count(arr,mid+1,se,qs,qe,st,2*si+2);
    return {left.first+right.first,left.second+right.second};
}

void updateValue(pair<int,int> *st,int ss,int se,int arr[],int index,int new_val,int si)
{
  if(ss==se)
  {
     if(new_val&1) //odd : 0,1
        st[si] = {0,1};
     else
        st[si] = {1,0};
     arr[index] = new_val;
  }
  else
  {
    int mid = getMid(ss,se);
    if(index<=mid)
       updateValue(st,ss,mid,arr,index,new_val,2*si+1);
    else
       updateValue(st,mid+1,se,arr,index,new_val,2*si+2);
    st[si].first = st[2*si+1].first+st[2*si+2].first;
    st[si].second = st[2*si+1].second+st[2*si+2].second;
  }
}
int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
     cin>>arr[i];
  pair<int,int> *st = construct_tree(arr, n);

  int q;
  cin>>q;

  while(q--)
  {
     int type,l,r;
     cin>>type>>l>>r;
     if(type == 0)
     {
       if(arr[l-1]%2 != r%2)
         updateValue(st,0,n-1,arr,l-1,r,0);
     }
     else
     {
       if(type==1)
           cout<<get_count(arr,0,n-1,l-1,r-1,st,0).first<<endl;
       else if(type==2)
           cout<<get_count(arr,0,n-1,l-1,r-1,st,0).second<<endl;
     }
  }
}
