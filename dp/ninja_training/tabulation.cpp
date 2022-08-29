
#include<bits/stdc++.h>
using namespace std;
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int> (4, 0));
    
    dp[0][0] = max(points[0][1],points[0][2]);
    dp[0][1] = max(points[0][0],points[0][2]);
    dp[0][2] = max(points[0][0],points[0][1]);
    dp[0][3] = max(points[0][0],max(points[0][1],points[0][2]));
    
    for(int day = 1;day<n;day++)
    {
        for(int last = 0; last<4; last++)
        {
            dp[day][last]=0;
            
            for(int task = 0;task<3;task++)
            {
                if(task!=last)
                {
                    int point = points[day][task]+ dp[day-1][task];
                    dp[day][last] = max(dp[day][last],point);
                }
            }
        }
    }
    
    for(int i=0;i<n;i++)
    { 
      for(int j=0;j<4;j++)
       {
          cout<<dp[i][j]<<" ";
       }
       cout<<endl;
    }cout<<endl;
    
    
    return dp[n-1][3];
}


int main()
{
  
   int n =4;
   vector<vector<int>> points
    {
        {2, 1, 3},
        {3, 4, 6},
        {10, 1, 6},
        {8,3,7}
    };
    /*
       int n =3;
   vector<vector<int>> points
    {
        {18, 11, 19},
        {4, 13, 7},
        {1, 8, 13}
      
    };*/
   
    
    cout<<ninjaTraining(n,points);



}


