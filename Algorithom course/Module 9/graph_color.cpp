#include <bits/stdc++.h>
using namespace std;

const int mx = 2e5 + 5;

int visited[mx];
int color[mx];

vector<int> adj_list[mx];

bool dfs(int node) {
  visited[node] = 1;

  for(int child : adj_list[node]) {
    if(visited[child] == 0) {
      // assign different color to adj_node
      if(color[node] == 1) {
        color[child] = 2;
      } else {
        color[child] = 1;
      }

      bool isBiColorAble = dfs(child);
      if(!isBiColorAble) {
        return false;
      }
    } else {
      // check if the color of adj_node is same as the current node
      if(color[child] == color[node]) {
        return false;
      }
    }
  }
  return true;
}


int main() {
  int n, m;
  cin >> n >> m;

  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
  }

  bool isBiColorAble = true;
  for (int i = 1; i <= n; i++){
    if(visited[i] == 0) {
      color[i] = 1;
      bool ok = dfs(i);
      if(!ok) {
        isBiColorAble = false;
        break;
      }
    }
  }

  if(!isBiColorAble) {
    cout << "IMPOSSIBLE" << "\n";
  } else {
    for(int i = 1; i <= n; i++) {
      cout << color[i] << " ";
    }
    cout << "\n";
  }

  return 0;
}

// building teams problem link : https://cses.fi/problemset/task/1668
/*
5 4
1 2
1 3
2 3
4 5 
Output -> IMPOSSIBLE

5 3
1 2
1 3
4 5
Output -> 
1 2 2 1 2
1 2 2 2 1
2 1 1 2 1
(2)  (1)
1 -- 2
|
3
(1)
(2)  (1)
4 -- 5
*/
