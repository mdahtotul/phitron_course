#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

vector<int> adj_list[N];

int visited[N];

void dfs(int src) {
  visited[src] = 1;

  for(int child: adj_list[src]) {
    if(!visited[child]) {
      dfs(child);
    }
  }
}


int get_size(int n) {
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    if(!visited[i]) {
      dfs(i);
      count++;
    }
  }

  return count;
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

  cout << get_size(n) << "\n";

  return 0;
}