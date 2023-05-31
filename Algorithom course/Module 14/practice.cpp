#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
const long long INF = 1e18;

vector<pair<int, int>> adj_list[N];
long long dist[N];
int visited[N], parent[N];
int nodes, edges;

void dijkstra(int src){
  priority_queue<pair<long long, int>> pq;

  for (int i = 1; i <= nodes; i++)
    dist[i] = INF;

  dist[src] = 0;
  pq.push({0, src});
  while(!pq.empty()){
    pair<long long, int> head = pq.top();
    pq.pop();

    int selected_node = head.second;
    if(visited[selected_node]) continue;

    visited[selected_node] = 1;
    for(auto child: adj_list[selected_node]) {
      int child_node = child.first;
      int edge_cost = child.second;
      int distance = dist[selected_node] + edge_cost;

      if(distance < dist[child_node]) {
        dist[child_node] = distance;
        parent[child_node] = selected_node;
        pq.push({-dist[child_node], child_node});
      }
    }
  }
}

void printList(int len) {
  for (int i = 0; i<len; i++) {
    for (int j = 0; j < adj_list[i].size(); j++) {
      cout<< "dst: " << adj_list[i][j].first << " node: " << adj_list[i][j].second << " vis: " << visited[adj_list[i][j].first] << " updated dist: " << dist[adj_list[i][j].first] << "\n";
    }
  }
}

void connectEdge(int u, int v, int w){
  adj_list[u].push_back({v, w});
  adj_list[v].push_back({u, w});
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> nodes >> edges;
  for (int i = 0; i < edges; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    connectEdge(u, v, w);
  }

  int src = 1;
  dijkstra(src);
  int dst = nodes;

  if(visited[dst] == 0){
    cout << -1 << "\n";
    return 0;
  }

  int cur_node = nodes;
  vector<int> path;

  while(1) {
    path.push_back(cur_node);
    if(cur_node == src)
      break;

    cur_node = parent[cur_node];
  }

  reverse(path.begin(), path.end());

  for(auto node: path) {
    cout << node << " ";
  }
  cout << "\n";

  return 0;
}