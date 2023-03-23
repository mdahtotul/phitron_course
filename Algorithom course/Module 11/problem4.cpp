#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj_list[N];
int visited[N], color[N];

bool dfs(int src) {
  visited[src] = 1;

  for(int child: adj_list[src]) {
    if(visited[child] == 0) {
      if(color[src] == 1) {
        color[child] = 2;
      } else {
        color[child] = 1;
      }

      bool ok = dfs(child);
      if(!ok) {
        return false;
      }
    } else {
      if(color[child] == color[src]) {
        return false;
      }
    }
  }

  return true;
}


int main(){
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
  }

  bool isBipartite = true;
  for(int i=1; i<=n; i++) {
    if(!visited[i]){
      color[i] = 1;
      bool ok = dfs(i);
      if(!ok) {
        isBipartite = false;
        break;
      }
    }
  }

  if(isBipartite) {
    cout << "YES" << "\n";
  } else {
    cout << "NO" << "\n";
  }

  return 0;
}