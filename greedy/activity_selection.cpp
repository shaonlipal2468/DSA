// C++ program for activity selection problem
// when input activities may not be sorted.
#include <bits/stdc++.h>
using namespace std;
struct Activitiy
{
	int start, finish;
};
bool activityCompare(Activitiy s1, Activitiy s2)
{
	return (s1.finish < s2.finish);
}

void printMaxActivities(Activitiy arr[], int n)
{
	sort(arr, arr+n, activityCompare);
	// The first activity always gets selected
	int i = 0;
	cout << "(" << arr[i].start << ", " << arr[i].finish << "), ";

	// Consider rest of the activities
	for (int j = 1; j < n; j++)
	{
	// If this activity has start time greater than or
	// equal to the finish time of previously selected
	// activity, then select it  ---- j : now seeing , i: previously selected job
	      if (arr[j].start >= arr[i].finish)
            	{
	             	cout << "(" << arr[j].start << ", "<< arr[j].finish << "), ";
	            	i = j;  //if j is selected update i
             	}
	}
}

// Driver program
int main()
{
  //when activities are not in sorted order
	Activitiy arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6},
									{5, 7}, {8, 9}};
	int n = sizeof(arr)/sizeof(arr[0]);
	printMaxActivities(arr, n);
	return 0;
}
