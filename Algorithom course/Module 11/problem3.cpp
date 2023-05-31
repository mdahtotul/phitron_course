#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int visited[N];
vector<int> adj_list[N];

bool dfs(int src) {
  visited[src] = 1;
  
  for(int child: adj_list[src]) {
    if(visited[child] == 0) {
      visited[child] = 1;
      bool got_cycle = dfs(child);
      if(got_cycle) {
        return true;
      }
    } else if(visited[child] == 1) {
      return true;
    }
  }

  visited[src] = 2;
  return false;
}

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj_list[u].push_back(v);
  }

  bool cycle_exists = false;
  for (int i = 1; i <= n; i++) {
    if(visited[i] == 0) {
      bool got_cycle = dfs(i);
      if(got_cycle) {
        cycle_exists = true;
        break;
      }
    }
  }

  if(cycle_exists) {
    cout << "YES";
  }else {
    cout << "NO";
  }

  return 0;
}