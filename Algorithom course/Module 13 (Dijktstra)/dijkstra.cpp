#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
const int INF = 1e9;
// const long long int INF = 1e18;
int nodes, edges;

vector<pair<int>> adj_list[N];

int distance[N], visited[N];

void dijkstra(int root) {
  for (int i = 1; i <= nodes; i++)
    distance[i] = INF;

  distance[root] = 0;

  for (int i = 0; i < nodes; i++) {
    int selected_node = -1;
    for (int j = 1; j < nodes; j++) {
      if(visited[j]) continue;
      if(selected_node == -1 || distance[selected_node] > distance[j] )
        selected_node = j;
    }
    visited[selected_node] = 1;

    for(auto adj_entry: adj_list[selected_node]) {
      int adj_node = adj_entry.first;
      int edge_cost = adj_entry.second;

      if(distance[selected_node] + edge_cost < distance[adj_node])
        distance[adj_node] = distance[selected_node] + edge_cost;
    }
  }

}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  
  cin >> nodes >> edges;

  for (int i = 0; i < nodes; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    adj_list[u].push_back({v, w});
    adj_list[v].push_back({u, w});
  }

  int root = 1;
  dijkstra(root);

  for (int i = 1; i <= nodes; i++) {
    cout << distance[i] << " ";
  }

  cout << "\n";

  return 0;
}
