#include  <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5, INF = 1e9;

vector<pair<int, int>> adj_list[N];
int dist[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n, m;
  cin >> n >> m;

  for(int i = 1; i <= n; i++)
    dist[i] = INF;
  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    adj_list[u].push_back({v, w});
  }

  int src = 1;
  dist[src] = 0;

  bool neg_cycle = false;

  for (int i = 1; i <= n; i++){
    for (int node = 1; node <= n; node++) {
      for(pair<int, int>adj_node: adj_list[node]) {
        int u = node;
        int v = adj_node.first;
        int w = adj_node.second;

        if(dist[u] + w < dist[v]) {
          dist[v] = dist[u] + w;
          if(i == n)
            neg_cycle = true;
        }
      }
    }
  }

  if(neg_cycle)
    cout << "Negative cycle detected\n ";
  else {
    for (int i = 1; i <= n; i++)
      cout << dist[i] << " ";
    
    cout << "\n";
  }



  return 0;
}