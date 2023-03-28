// Message Route - CSES Problem Set link: https://cses.fi/problemset/task/1667

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

vector<int> adj_list[N];
int visited[N], level[N], parent[N];

void bfs(int src) {
  visited[src] = 1;
  level[src] = 1;
  parent[src] = -1;

  queue<int> q;
  q.push(src);

  while(!q.empty()) {
    int head = q.front();
    q.pop();

    for(int child: adj_list[head]) {
      if(!visited[child]) {
        parent[child] = head;
        visited[child] = 1;
        level[child] = level[head] + 1;
        q.push(child);
      }
    }
  }
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
  }

  int root = 1;
  bfs(root);

  int dst = n;
  if(!visited[dst]) {
    cout << "IMPOSSIBLE" << "\n";
    return 0;
  }

  cout << level[dst] << "\n";

  int selected = dst;
  vector<int> path;

  while(1) {
    path.push_back(selected);
    if(selected == root)
      break;
    selected = parent[selected];
  }

  reverse(path.begin(), path.end());

  for(int node: path) {
    cout << node << " ";
  }
  cout << "\n";

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