#include <bits/stdc++.h>
using namespace std;

const int N = 5000;
const long long INF = 1e18;

long long dist[N];
long long parent[N];

vector<pair<int, int>> adj_list[N];

void bellman_ford(int n){
  bool neg_cycle = false;
  int last_updated_node = -1;

  for (int i = 1; i<=n; i++) {
    for (int node = 1; node <= n; node++) {
      for(pair<int, int>adj_node: adj_list[node] ){
        int u = node;
        int v = adj_node.first;
        int w = adj_node.second;

        if(dist[u] + w < dist[v]) {
          dist[v] = dist[u] + w;
          parent[v] = u;
          if(i == n) {
            neg_cycle = true;
            last_updated_node = v;
          }
        }
      }
    }
  }

  if(neg_cycle) {
    cout << "YES\n";
    int selected_node = last_updated_node;
    for (int i = 1; i < n ; i++) {
      selected_node = parent[selected_node];
    }
    int first = selected_node;
    vector<int> cycle;
    cycle.push_back(selected_node);

    while(1) {
      selected_node = parent[selected_node];
      cycle.push_back(selected_node);
      if(first == selected_node) break;
    }
    reverse(cycle.begin(), cycle.end());
    for(auto it: cycle)
      cout << it << " ";
  } else {
    cout << "NO\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;

  for (int i = 0; i <= n; i++) {
    dist[i] = INF;
  }

  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj_list[u].push_back({v, w});
  }

  bellman_ford(n);

  return 0;
}

/*
Input
------
4 5
1 2 2
2 3 2
1 3 18
2 4 -5
3 5 -5
4 1 -5
5 6 -6
6 1 3
1 2 192 3 -5
3 4 -5
4 5 -5
5 1 -5
Output
--------
YES
1 2 3 4 5 1
*/