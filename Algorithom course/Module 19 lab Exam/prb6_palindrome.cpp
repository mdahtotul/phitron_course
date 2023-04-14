#include <bits/stdc++.h>
using namespace std;
 
bool isPalindrome(string str)
{
  unordered_map<char, int> mp;
  for (int i = 0; i < str.length(); i++)
    mp[str[i]]++;

  int oddCount = 0;
  for(auto x: mp){
    if(x.second % 2 != 0)
      oddCount++;
  }

  if((str.length() % 2 == 0 && oddCount == 0) || (str.length() % 2 == 1 && oddCount == 1)) {
    return true;
  }

  return false;
}
 
int main()
{
    string s;
    cin >> s;
    bool valid = isPalindrome(s);

    if(valid)
      cout << "YES \n";
    else 
      cout << "NO \n";
    
    return 0;
}