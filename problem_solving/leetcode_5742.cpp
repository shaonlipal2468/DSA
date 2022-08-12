//leetcode 5742
#include<bits/stdc++.h>
using namespace std;

string sortSentence(string s) {

    vector<int> start_index;
    vector<int> end_index;
    vector<int> number;
    start_index.push_back(0);
    for(int i=0;i<s.size();i++)
    {
        if(isdigit(s[i]))
        {
            end_index.push_back(i-1);
            int num = s[i] - '0';
            number.push_back(num);
            if((i+2)<s.size())
                 start_index.push_back(i+2);
            i++;
        }
    }
    int number_of_substr=start_index.size();
    string answer[number_of_substr+1];

    for(int i=0;i<number.size();i++)
    {
      int start = start_index[i];
      int end=end_index[i];
      answer[number[i]]= s.substr(start,end-start+1);
    }
   string ans=answer[0];
   string space=" ";
   for(int i=1;i <number_of_substr ; i++){
      ans.append(answer[i]);
      ans.append(space);
    }
    ans.append(answer[number_of_substr]);
    return ans;
}
int main()
{
   string S ="is3 shaonli4 My1 pal5 name2";
   cout<<sortSentence(S)<<endl;
}
