//maximum number of trains for which stoppage can be provided
#include<bits/stdc++.h>
using namespace std;

struct train
{
  int train_id;
  int arrival_time;
  int departure_time;
  int platform;
};

bool comparator(train a,train b)
{
  return a.departure_time<b.departure_time;
}

int maxStop(train arr[],int platform,int total_train)
{
  int max_train=0;
  vector<int> flag(platform+1);
  fill(flag.begin(), flag.end(), -1); //initialization
  //flag will contain -1 (means empty) or the train that is now on the platform's departure_time

  sort(arr,arr+total_train,comparator);

  cout<<"id ARR DEP PLATFORM"<<endl;
  for(int i=0;i<total_train;i++)
    cout<<arr[i].train_id<<" "<<arr[i].arrival_time<<" "<<arr[i].departure_time<<" "<<arr[i].platform<<endl;

  cout<<"Trains selected : ";
  for(int i=0;i<total_train;i++)
  {
    if(flag[arr[i].platform]==-1 || arr[i].arrival_time >= flag[arr[i].platform])
    //means platform is empty or current train's arrival train is greater than located train on that platform's departure_time
    {
        max_train++;
        flag[arr[i].platform]=arr[i].departure_time;
        cout<<arr[i].train_id<<" ";
    }
  }
  cout<<endl;
  return max_train;
}
int main()
{
    train arr[] =   { {1,1000, 1030, 1},
                      {2,1010, 1030, 1},
                      {8,1010, 1030, 1},
                      {3,1025, 1040, 1},
                      {4,1130, 1145, 2},
                      {5,1130, 1140, 2},
                      {6,1150, 1155, 2},
                      {7,1005, 1009, 1}};

    int platform=2;

   /*
    train arr[]={{1,1010,1030,1},
                 {2,1000,1030,1},
                 {3,1000,1020,2},
                 {4,1030,1230,2},
                 {5,1200,1230,3},
                 {6,900,1005,1}};

    int platform =3;
    */
    int total_train = sizeof(arr)/sizeof(arr[0]);
    cout << maxStop(arr,platform,total_train)<<" : Maximum number of trains for which stoppage can be provided "<<endl;
}
