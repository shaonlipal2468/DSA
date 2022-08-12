#include<bits/stdc++.h>
using namespace std;
struct Item{
    int value;
    int weight;
};

static bool comparator(struct Item a,struct Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}
//Function to get the maximum total value in the knapsack.
double fractionalKnapsack(int w, Item arr[], int n)
{
    // Your code here
    double profit=0;
    sort(arr,arr+n,comparator);

    for(int i=0;i<n;i++)
    {
        if(arr[i].weight<=w)
        {
             profit+= arr[i].value;
             w=w-arr[i].weight;
        }
        else
        {
             double remaining_weight = w;
             profit+= remaining_weight * arr[i].value/arr[i].weight;
             break;
        }

    }
    return profit;
}

int main()
{
    int W = 50; //    Weight of knapsack
    Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };

    int n = sizeof(arr) / sizeof(arr[0]);

    // Function call
    cout << "Maximum value we can obtain = " << fractionalKnapsack(W, arr, n)<<endl;

}
