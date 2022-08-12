#include<bits/stdc++.h>
using namespace std;
int precedence(char op)
{
  if(op == '+'||op == '-')
   return 1;
   else if(op == '*'||op == '/')
   return 2;
   else return 0;
}

int applyOp(int a, int b, char op){
    switch(op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

char choose_operator(int chance)
{
  if(chance == 0)
      return '*';
  else if(chance == 1)
      return '/';
  else if(chance == 2)
      return '+';
  else
      return '-';
}
int clumsy(int n)
{
  if(n==1)
    return 1;
  stack<int> operands;
  stack<char> operators;
  int chance=1;
  char opert;
  operands.push(n);
  operators.push('*');

  for(int i=n-1;i>=1;i--)
  {
      operands.push(i);
      chance=chance %4;
      opert=choose_operator(chance);
      chance++;
      while(operators.size()>0 && precedence(opert)<= precedence(operators.top()))
      {
        int opr2= operands.top();
        operands.pop();
        int opr1 = operands.top();
        operands.pop();
        int temp_ans = applyOp(opr1,opr2,operators.top());
        operators.pop();
        operands.push(temp_ans);
      }

      if(i==1)
         break;
      else operators.push(opert);
  }

  while(operators.size()>0)
  {
    int opr2= operands.top();
    operands.pop();
    int opr1 = operands.top();
    operands.pop();

    int temp_ans = applyOp(opr1,opr2,operators.top());
    operators.pop();
    operands.push(temp_ans);
  }
  return operands.top();
}

   int main()
   {
     int n=10;
     cout<<clumsy(n)<<endl;

   }


   /*
   void clumsy(int n) {
          string exp="" ;
          int chance=0;

          for(int i=n;i>=2;i--)
          {
              string temp =to_string(i);
              //cout<<temp;
              exp.append(temp);

              chance=chance %4;
              if(chance == 0)
                  exp.append("*");
              else if(chance == 1)
                  exp.append("/");
              else if(chance == 2)
                  exp.append("+");
              else if(chance == 3)
                  exp.append("-");
              chance++;

          }
          exp.append("1");
          cout<<exp;
      }*/
