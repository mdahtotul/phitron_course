#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 2;
vector<int> adj_list[N];
int visited[N];

void bfs(int src){
  queue<int> q;
  q.push(src);
  visited[src] = 1;

  while(!q.empty()) {
    int head = q.front();
    q.pop();

    for(int child: adj_list[head]) {
      if(!visited[child]) {
        visited[child] = 1;
        q.push(child);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
  }

  int root = 1;
  bfs(root);

  int dst = n;

  if(!visited[dst]) {
    cout << "NO" << "\n";
  } else {
    cout << "YES" << "\n";
  }
  return 0;
}

/*
Input:
10 8
1 3
3 4
3 6
4 6
2 5
1 7
3 10
9 8
Output:
YES

Input:
8 6
7 4
7 6
4 6
2 5
1 3
7 8
Output:
NO
*/