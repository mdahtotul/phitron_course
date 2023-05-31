/*
 - state: LCS(i, j) -> Length of the longest common subsequence between s1[i..n] and s2[j..m]
 - recurrence relation: if(s1[i] == s2[j]) LCS(i+1, j+1)
                        else max(LCS(i+1), j), LCS(i, j+1)
 - base case: if(i == s1.size() || j == s2.size()) return 0;
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 3001;

int dp[N][N];
int n, m;
string s1, s2;

int LCS_tab(int i, int j) {
  
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> s1 >> s2;

  n = s1.size(), m = s2.size();

  cout << LCS_tab(0, 0) << "\n";

  return 0;
}