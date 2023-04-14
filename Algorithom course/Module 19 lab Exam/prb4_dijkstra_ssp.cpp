#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

const long long INF = 1e18;

vector<pair<int, int>> adj_list[N];

long long dist[N];
int vis[N], parent[N];

void dijkstra(int src, int n, int m) {
  for (int i = 1; i <= n; i++) {
    dist[i] = INF;
  }

  dist[src] = 0;
  priority_queue<pair<int, int>> pq;
  pq.push({0, src});

  while(!pq.empty()) {
    pair<int, int> head = pq.top();
    pq.pop();
    int s_node = head.second;
    if(!vis[s_node]) {
      vis[s_node] = 1;

      for(auto child: adj_list[s_node]) {
        int child_node = child.first;
        int cost = child.second;
        if(dist[child_node] > dist[s_node]  + cost) {
          dist[child_node] = dist[s_node] + cost;
          parent[child_node] = s_node;
          pq.push({-dist[child_node], child_node});
        }
      }
    }
  }
}

void pathPrint(int dis, int src) {
  if(!vis[dis]) {
    cout << -1 << "\n";
  } else {
    int cur_node = dis;
    vector<int> path;
    while(1) {
      path.push_back(cur_node);
      if(cur_node == src)
        break;
      cur_node = parent[cur_node];
    }

    reverse(path.begin(), path.end());
    for(auto it: path) {
      cout << it << " ";
    }
    cout << "\n";
  }
}

int main() {
  int n, m;
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;

  for (int i = 1; i <= m; i++){
    int u, v, w;
    cin >> u >> v >> w;
    adj_list[u].push_back({v, w});
    adj_list[v].push_back({u, w});
  }

  int src = 1;
  dijkstra(src, n, m);

  pathPrint(n, src);

  return 0;
}
/*
Input:
--------
10 10
1 4 201
2 3 238
3 4 40
3 6 231
3 8 45
4 5 227
4 6 58
4 9 55
5 7 14
6 10 242

Output:
--------
1 4 6 10 
*/
