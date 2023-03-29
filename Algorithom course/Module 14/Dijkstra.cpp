// codeforces Dijkstra problem set link: https://codeforces.com/problemset/problem/20/C

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
// max vertices or edges is 1e5 and max weight is 1e6. 
// max_distance = max vertices or edges + max weight = 1e11. To store this value we have to use long long
const long long INF = 1e18;
int nodes, edges;

vector<pair<int, int>> adj_list[N];
long long dist[N];
int visited[N], parent[N];

void dijkstra(int src) {
  // initialize all distances to infinity
  for (int i = 1; i <= nodes; i++) {
    dist[i] = INF;
  }
  // initialize src node as unvisited
  dist[src] = 0;
  // the pair is {distance, node}
  priority_queue<pair<long long, int>> pq;
  // distance of source node from itself is 0
  pq.push({0, src});

  while (!pq.empty()) {
    pair<long long, int> head = pq.top();
    pq.pop();

    int selected_node = head.second;
    if(visited[selected_node]) continue;
    visited[selected_node] = 1;

    for(auto child : adj_list[selected_node]) {
      int child_node = child.first;
      int edge_cost = child.second;

      if(dist[selected_node] + edge_cost < dist[child_node]) {
        dist[child_node] = dist[selected_node] + edge_cost;
        parent[child_node] = selected_node;
        pq.push({-dist[child_node], child_node});
      }
    }
  }
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> nodes >> edges;
  for(int i = 0; i < edges; i++){
    int u, v, w;
    cin >> u >> v >> w;
    adj_list[u].push_back({v, w});
    adj_list[v].push_back({u, w});
  };

  int src = 1;
  dijkstra(src);

  if(visited[nodes] == 0) {
    cout << -1 << "\n";
    return 0;
  }
  
  int current_node = nodes;
  vector<int> path;

  while (true) {
    path.push_back(current_node);
    if(current_node == src)
      break;

    current_node = parent[current_node];
  }

  reverse(path.begin(), path.end());

  for(auto node: path) {
    cout << node << " ";
  }
  cout << "\n";
  return 0;
}

/*
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1
*/