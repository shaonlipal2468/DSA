#include<bits/stdc++.h>
using namespace std;

void print_stair_path(int n,string &path)
{
    if(n<0)
    {
        if(path.size()!=0)
            path.pop_back();
        return;
    }
    if(n==0)
    {

        cout<<path<<endl;
        if(path.size()!=0)
            path.pop_back();
        return;
    }
    else
    {
        print_stair_path(n-1,path.append("1"));
        print_stair_path(n-2,path.append("2"));
        print_stair_path(n-3,path.append("3"));
        if(path.size()!=0)
             path.pop_back();
    }
}

int count(int n)
{
    if(n<0)
      return 0;
    if(n==0)
      return 1;
    else
      return count(n-1)+count(n-2)+count(n-3);
}



int main()
{
   int n;
   n=4;
   string path="";
   print_stair_path(n,path);
   cout<<"total number of paths "<<count(n);
   return 0;
}
