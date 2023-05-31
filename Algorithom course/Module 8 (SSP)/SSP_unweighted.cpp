#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj_list[], int nodes, int src, int level[]) {
  queue<int> q;
  int visited[nodes];
  memset(visited, 0, sizeof(visited));

  visited[src] = 1;
  level[src] = 0;
  q.push(src);

  while(!q.empty()) {
    int head = q.front();
    q.pop();

    for(int child: adj_list[head]) {
      if(!visited[child]) {
        visited[child] = 1;
        level[child] = level[head] + 1;
        q.push(child);
      }
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

  for (int i = 0; i < edges; i++) {
    int u, v;
    cin >> u >> v;
    connectEdge(adj_list, u, v);
  }

  int src = 0;
  bfs(adj_list, nodes, src, level);

  for(int i = 0; i < nodes; i++) {
    cout << "Node " << i << " -> level: " << level[i] << "\n";
  }

  return 0;
}



/*
(0)  (1)  (2) (3)
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
5 4
1 2

6 7
0 1
0 3
0 4
1 2
1 5
5 4
4 2
*/
