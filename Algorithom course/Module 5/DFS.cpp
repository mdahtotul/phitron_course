#include <bits/stdc++.h>
using namespace std;

bool isPalindrom( string str){
   int len = str.size();

   if(str == "" || len == 1)
      return true;

   string smallStr = str.substr(1, len-2);
   return isPalindrom(smallStr) && (str[0] == str.back());
}

int main(){

   string s;
   cin>>s;

   isPalindrom(s) ? cout<<"Palindrome" : cout<<"Not Palindrome";

   return 0;
}
