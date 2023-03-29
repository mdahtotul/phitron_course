#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj_list[], int src, int level[], int visited[]) {
  visited[src] = 1;

  for (int child: adj_list[src]) {
    if(!visited[child]){
      visited[child] = 1;
      level[child] = level[src] + 1;
      dfs(adj_list, child, level, visited);
    }
  }
}

void connectEdge(vector<int> adj_list[], int u, int v) {
  adj_list[u].push_back(v);
  adj_list[v].push_back(u);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int nodes, edges;
  cin >> nodes >> edges;

  vector<int> adj_list[nodes];
  int level[nodes];
  memset(level, 0, sizeof(level));
  int visited[nodes];
  memset(visited, 0, sizeof(visited));


  for (int i = 0; i < edges; i++) {
    int u, v;
    cin >> u >> v;
    connectEdge(adj_list, u, v);
  }

  int src = 0;
  dfs(adj_list, src, level, visited);

  for(int i = 0; i < nodes; i++) {
    cout << "Node " << i << " -> level: " << level[i] << "\n";
  }

  return 0;
}



/*
(0)  (1)  (4) (5)
0----1----2----3
     |    |
     |    |
     5----4
    (2)  (3)

6 6
0 1
2 3
1 5
2 4
1 2
5 4

6 7
0 1
0 3
0 4
1 2
1 5
5 4
4 2
*/
