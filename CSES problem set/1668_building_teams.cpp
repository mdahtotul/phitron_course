#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
vector<int> adj_list[N];
int visited[N], color[N];

bool dfs(int src){
  visited[src] = 1;

  for(int child: adj_list[src]) {
    if(!visited[child]) {
      color[src] == 1 ? color[child] = 2 : color[child] = 1;
      bool is_bicolor_able = dfs(child);
      if(!is_bicolor_able)
        return false;
    } else {
      if(color[src] == color[child])
        return false;
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

  bool is_bicolor_able = true;
  for(int i = 1; i <= n; i++){
    if(!visited[i]) {
      color[i] = 1;
      bool ok = dfs(i);
      if(!ok) {
        is_bicolor_able = false;
        break;
      }
    }
  }

  if(!is_bicolor_able) {
    cout << "IMPOSSIBLE" << "\n";
  } else {
    for(int i=1; i<=n; i++)
      cout << color[i] << " ";
  }
  cout << "\n";

  return 0;
}

/*
Input:
5 3
1 2
1 3
4 5

Output:
1 2 2 1 2
*/