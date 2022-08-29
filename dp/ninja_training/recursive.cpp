#include<bits/stdc++.h>
using namespace std;

int recursive_function(int day,int last_task,vector<vector<int>> &points)
{
    int maxi;
    //base case
    if(day == 0)
    {
        maxi=0;
        for(int task=0;task<3;task++)
        {
            if(task!=last_task)
                maxi = max(maxi,points[0][task]);  
        }
        return maxi;
    }
    
    
    //recursive cases from day 1 to n-1
    maxi=0;
    for(int task=0;task<3;task++)
    {
        if(task!=last_task)
        {
            int point = points[day][task]+ recursive_function(day-1,task,points);
            maxi = max(maxi,point);
        }
    }
    return maxi;
}



int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    return recursive_function(n-1,3,points);
}


int main()
{
  /*
   int n =4;
   vector<vector<int>> points
    {
        {2, 1, 3},
        {3, 4, 6},
        {10, 1, 6},
        {8,3,7}
    };
    */
       int n =3;
   vector<vector<int>> points
    {
        {18, 11, 19},
        {4, 13, 7},
        {1, 8, 13}
      
    };
   
    
    cout<<ninjaTraining(n,points);



}



