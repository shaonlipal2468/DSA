#include<bits/stdc++.h>
using namespace std;
void print_vector(vector<int> v,int n)
{
  cout<<"The factorial of "<<n<<" is : ";
  for(int i=0;i<v.size();i++)
      cout<<v[i];
  cout<<endl;
}
vector<int> multiply(int each_number,vector<int> result)
    {
        int carry=0;
        for(int i=0;i<result.size();i++)
        {
            int product = result[i]*each_number+carry;
            result[i]=product%10;
            carry = product/10;
        }
        while(carry)
        {
            result.push_back(carry%10);
            carry= carry/10;
        }
        return result;
    }
vector<int> factorial(int n)
   {
        vector<int> result;
        result.push_back(1);
        if(n<2)
              return result;
        for(int each_number=2;each_number<=n;each_number++)
              result=multiply(each_number,result);
        reverse(result.begin(),result.end());
        return result;
    }
int main()
    {
      int n=100;
      vector<int> result=factorial(n);
      print_vector(result,n);

    }
