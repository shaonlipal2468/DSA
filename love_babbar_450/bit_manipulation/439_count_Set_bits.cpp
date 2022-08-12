#include <bits/stdc++.h>
using namespace std;

    int setBits(int N) {
        //Kernighan's Algorithm
        int counter =0;
        while(N>0)
        {
             int right_set_bit_mask = N&-N;
             N-=right_set_bit_mask;
             counter++;
        }
        return counter;
    }
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;


        int cnt = setBits(N);
        cout << cnt << endl;
    }
    return 0;
}
