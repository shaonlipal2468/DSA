


#include <iostream>
using namespace std;


double calculate(int x,double y)
{
    if(x%5 ==0 && x<=y)
        return y-x-0.5;
    return y;
}

int main() {
	// your code goes here
	int x;
	double y;
	cin>>x>>y;
	cout<<calculate(x,y);

	return 0;
}
