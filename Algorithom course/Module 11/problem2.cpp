#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int visited[N], level[N];

vector<int> adj_list[N];

void bfs(int src) {
  queue<int> q;
  q.push(src);
  visited[src] = 1;

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

int main() {
  int n=6, m=7;

  adj_list[0] = {1, 3, 4};
  adj_list[1] = {0, 2, 5};
  adj_list[2] = {1, 4};
  adj_list[3] = {0};
  adj_list[4] = {0, 2, 5};
  adj_list[5] = {5, 4};
  adj_list[6] = {1, 4};

  int src = 0;
  bfs(src);

  for (int i = 0; i < n; i++) {
    cout << "node " << i << " -> level: " << level[i] << "\n";
  }
  return 0;
}
