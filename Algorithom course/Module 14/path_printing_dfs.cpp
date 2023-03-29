#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj_list[N], path;
int visited[N];

void printPath() {
  cout << path.size() << endl;
  for(int i = 0; i < path.size(); i++) {
    cout << path[i] << " ";
  }
}

void dfs(int src, int dst) {
  path.push_back(src);
  if(src == dst) {
    printPath();
    return;
  }

  visited[src] = 1;
  for(int child: adj_list[src]) {
    if(!visited[child]) {
      dfs(child, dst);
    }
  }

  path.pop_back();
}

void connectEdge(int u, int v) {
  adj_list[u].push_back(v);
  adj_list[v].push_back(u);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int nodes, edges;
  cin >> nodes >> edges;
  for (int i = 0; i < edges; i++){
    int u, v;
    cin >> u >> v;
    connectEdge(u, v);
  }

  int src = 1, dst = nodes;
  dfs(src, nodes);
  return 0;
}

/*
Input:
5 5
1 2
1 3
1 4
2 3
5 4

Output:
3
1 4 5
*/