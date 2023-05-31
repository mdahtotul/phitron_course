#include <bits/stdc++.h>
using namespace std;

/*
  - state: f(n) -> longest path from root node n to leaf
  - recurrence relation: f(n) -> max{f(p_1), f(p_2), ...., f(p_m)} + 1
  - base case: f(root) = 0

  node = [child_1, child_2, ......]
  parent = [parent_1, parent_2, ......]
*/

const int N = 1e5 + 5;
vector<int> parent_list[N];

int dp[N];
int root, target;

int maxDistance(int node){
  // base case
  if(node == root) return 0;
  // memoization
  if (dp[node] != -1)
    return dp[node];

  // recurrence relation
  int ans = 0;
  for (int parent : parent_list[node])
    ans = max(ans, maxDistance(parent));

  ans++;
  dp[node] = ans;
  return ans;
}

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    parent_list[v].push_back(u);
  }

  memset(dp, -1, sizeof(dp));

  cin >> root >> target;

  cout<<maxDistance(target)<<"\n"; // longest path from target to leaf
  return 0;
}

/*
4 4
1 3
3 4
1 4
4 2

1 2
*/