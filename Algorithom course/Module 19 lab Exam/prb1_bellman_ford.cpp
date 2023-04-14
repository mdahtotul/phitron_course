#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const long long INF = 1e18;

vector<pair<int, int>> adj_list[N];
long long dist[N];

bool bellman_ford(int n) {
  for (int i = 1; i <= n; i++) {
    for (int node = 1; node <= n; node++) {
      for(pair<int,int>adj_node: adj_list[node]) {
        int u = node;
        int v = adj_node.first;
        int w = adj_node.second;

        if(dist[u] + w < dist[v]) {
          dist[v] = dist[u] + w;
          if(i == n) {
            return true;
          }
        }
      }
    }
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++)
    dist[i] = INF;

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj_list[u].push_back({v, w});
  }

  bool neg_cycle = false;

  neg_cycle = bellman_ford(n);

  if(neg_cycle) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }

  return 0;
}

/*
Input:
--------
4 5
1 2 1
2 4 1
3 1 1
4 1 -3
4 3 -2

Output:
--------
Yes

Input:
--------
5 7
1 2 3
1 3 2
2 3 1
2 4 -8
4 1 2
2 5 5
4 5 2

Output:
--------
Yes
*/