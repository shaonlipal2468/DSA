#include<bits/stdc++.h>
using namespace std;

int minimumCostOfBreaking(int horizontal_cost[],int vertical_cost[],int length,int width)
{
   int ans=0;
   int i=0,j=0;
   int horizontal_block =1;
   int vertical_block =1;

   sort(horizontal_cost,horizontal_cost+length,greater<int>());
   sort(vertical_cost,vertical_cost+width,greater<int>());

   while(i<length && j<width)
   {
     if(horizontal_cost[i]>=vertical_cost[j]) //cut in vertically
     //If we are cutting vertically then we have to took all horizontal pieces
     //Number of horizontal block will be increased by 1
     {
         ans +=horizontal_cost[i]* vertical_block;
         horizontal_block++;
         i++;
     }

     else  //cut horizontally
     {
       //If we are cutting horizontally then we have to took all vertical pieces
       //Number of vertical block will be increased by 1
       ans +=vertical_cost[j]* horizontal_block;
       vertical_block++;
       j++;
     }
   }

   while(i<length)
   {
       ans +=horizontal_cost[i]* vertical_block;
       i++;
       //horizontal_block++;
   }

   while(j<width)
   {
     ans +=vertical_cost[j]* horizontal_block;
     j++;
     //vertical_block++;
   }

//39 and 46 these two lines are useless

   return ans;
}
int main()
{
    int length = 6, width = 4;
    int horizontal_cost[length-1] = {2, 1, 3, 1, 4};
    int vertical_cost[width-1] = {4, 1, 2};
    cout << minimumCostOfBreaking(horizontal_cost, vertical_cost, length-1, width-1);
    return 0;
}
