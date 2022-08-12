//https://leetcode.com/problems/valid-palindrome/
/*
Given a string s, determine if it is a palindrome,
considering only alphanumeric characters and ignoring cases.
Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

*/
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string S) {

       int low=0;
       int high=S.size()-1;

       while(low<=high)
       {
           S[low]=tolower(S[low]);
           S[high]=tolower(S[high]);
           if(!isalnum(S[low]) && !isalnum(S[high]))
           {
               low++;
               high--;
           }
           else if(!isalnum(S[low]) && isalnum(S[high]))
                    low++;
           else if(isalnum(S[low]) && !isalnum(S[high]))
                    high--;
           else {
               if(S[low]!=S[high])
                   return 0;
               low++;
               high--;
           }

       }
       return 1;

 }


 int main()
 {
    string S ="A man, a plan, a canal: Panama";
    cout<<isPalindrome(S);

 }
