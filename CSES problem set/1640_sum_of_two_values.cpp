#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, sum;
  cin >> n >> sum;

  int idxL = 0, idxR = n - 1;

  vector<pair<int, int>> table;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    table.push_back({num, i+1});
  }

  sort(table.begin(), table.end());

  while(idxL != idxR) {
    int x = table[idxL].first + table[idxR].first;
    if(sum == x) {
      cout<< table[idxL].second << " " << table[idxR].second;
      return 0;
    } else if(sum > x) {
      idxL++;
    } else if (sum < x) {
      idxR--;
    }
  }

  cout << "IMPOSSIBLE" << "\n";
}