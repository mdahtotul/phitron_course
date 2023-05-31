#include <bits/stdc++.h>
using namespace std;
#define nl '\n';
typedef long long ll;

int n;

vector<vector<int>> ans;

bool solution_found(int idx, vector<int>& state) {
  return idx == n;
}

vector<int> get_candidates(vector<int>& state) {
  map<int, int> taken;
  for (int x: state) {
    taken[x] = 1;
  }

  vector<int> candidates;
  for (int i = 1; i <= n; i++) {
    if(taken.count(i) == 0)
      candidates.push_back(i);
  }

  return candidates;
}

void backtrack(int idx, vector<int>& state) {
  if(solution_found(idx, state)) {
    ans.push_back(state);
    return;
  }

  vector<int> candidates = get_candidates(state);
  for(int candidate: candidates) {
    state[idx] = candidate;
    backtrack(idx + 1, state);
    state[idx] = 0;
  }

}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n;

  vector<int> initial_state(n);
  backtrack(0, initial_state);

  for(vector<int> permutation: ans) {
    for(auto x: permutation)
      cout << x << " ";

    cout << nl;
  }
}