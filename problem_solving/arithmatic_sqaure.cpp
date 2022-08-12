#include<bits/stdc++.h>
using namespace std;

int solve(int arr[3][3])
{
  int count=0;
  if(arr[0][0]+arr[2][0] == 2*arr[1][0])
     count++;
  if(arr[0][0]+arr[0][2] == 2*arr[0][1])
     count++;
  if(arr[2][0]+arr[2][2] == 2*arr[2][1])
     count++;
  if(arr[0][2]+arr[2][2] == 2*arr[1][2])
     count++;

  int count_2=0,over_cnt=0;
  int x;
  if((arr[0][0]+arr[2][2])%2==0)
  {
      x= (arr[0][0]+arr[2][2])/2;
      count_2++;
      if(arr[0][2]+arr[2][0]==2*x)
         count_2++;
      if(arr[0][1]+arr[2][1]==2*x)
         count_2++;
      if(arr[1][0]+arr[1][2]==2*x)
         count_2++;

  }
  over_cnt = max(over_cnt,count_2);
  count_2=0;

  if((arr[0][2]+arr[2][0])%2==0)
  {
      x= (arr[0][2]+arr[2][0])/2;
      count_2++;
      if(arr[0][0]+arr[2][2]==2*x)
         count_2++;
      if(arr[0][1]+arr[2][1]==2*x)
         count_2++;
      if(arr[1][0]+arr[1][2]==2*x)
         count_2++;

  }
  over_cnt = max(over_cnt,count_2);
  count_2=0;

  if((arr[0][1]+arr[2][1])%2==0)
  {
      x= (arr[0][1]+arr[2][1])/2;
      count_2++;
      if(arr[0][0]+arr[2][2]==2*x)
         count_2++;
      if(arr[0][2]+arr[2][0]==2*x)
         count_2++;
      if(arr[1][0]+arr[1][2]==2*x)
         count_2++;

  }
  over_cnt = max(over_cnt,count_2);
  count_2=0;
  if((arr[1][0]+arr[1][2])%2==0)
  {
      x= (arr[1][0]+arr[1][2])/2;
      count_2++;
      if(arr[0][0]+arr[2][2]==2*x)
         count_2++;
      if(arr[0][2]+arr[2][0]==2*x)
         count_2++;
      if(arr[0][1]+arr[2][1]==2*x)
         count_2++;

  }



  return count+over_cnt;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int arr[3][3];

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(i==1 && j==1)
                  continue;
                else
                   cin>>arr[i][j];
            }
        }
        int last = arr[0][0];
        bool flag = true;

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(i==1 && j==1)
                  continue;
                else
                  {
                     if(arr[i][j]!=last)
                       {
                         flag=false;
                         break;
                       }
                  }
            }


        }
        if(flag==true)
          cout<<8<<endl;
        else
        cout<<solve(arr)<<endl;
    }
}
