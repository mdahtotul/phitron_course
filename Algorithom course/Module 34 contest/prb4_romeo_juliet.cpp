#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
vector<int> adj_list[N];
int vis[N];

bool bfs(int src, int k) {
  queue <int> q;
  q.push(src);
  vis[src] = 1;

  int step = 0;
  
  while(!q.empty()) {
    int head = q.front();
    q.pop();

    for(int node: adj_list[head]){
      if(!vis[node]) {
        vis[node] = 1;
        q.push(node);
      } else if(vis[node] == 1) {
        return true;
      }
      if(step == k) {
        return false;
      }
      step++;
    }
  }
  return false;
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

  if(x == y) {
    cout << "YES\n";
    return 0;
  }
  if(n < k) {
    cout << "NO\n";
    return 0;
  }

  bool ans1 = bfs(x, k);
  bool ans2 = bfs(y, k);
  bool ans = ans1 || ans2;
  cout << (ans ? "YES" : "NO") << "\n";
  return 0;
}