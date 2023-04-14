#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;
const int INF = 1e9;
int dist[N][N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dist[i][j] = INF;
    } 
  }

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    dist[u][v] = w;
  }

  for (int i = 1; i <= n; i++) {
    d[i][i] = 0;
  }

  for (int k = 1; k <= n; k++) {
    for (int u = 1; u <= n; u++) {
      for (int v = 1; v <= n; v++) {
        dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << dist[i][j] << " ";
    }
    cout << endl;
  }
  
  return 0;
}