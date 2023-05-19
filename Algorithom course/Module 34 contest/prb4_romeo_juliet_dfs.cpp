#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
vector<int> adj_list[N];
int vis[N];

bool dfs(int src, int k) {
  vis[src] = 1;
  for(int node: adj_list[src]) {
    dfs(node, k);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, e;
  cin >> n >> e;

  for(int i=0; i<e; i++) {
    int u, v;
    cin >> u >> v;
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
  }

  int x, y, k;
  cin >> x >> y >> k;

  bool ans1 = dfs(x, k);
  bool ans2 = dfs(y, k);
  bool ans = ans1 || ans2;
  cout << (ans ? "YES" : "NO") << "\n";
  return 0;
}