// https://lightoj.com/problem/back-to-underworld

#include <bits/stdc++.h>
using namespace std;
#define nl "\n";

const int N = 20005, black = 1, red = 2;

vector<int> adj_list[N];
int visited[N], color[N];
int vamp = 0, lyk = 0;

void bfs(int src) {
  queue<int> q;
  visited[src] = 1;
  color[src] = black;
  vamp++;
  q.push(src);

  while(!q.empty()) {
    int top = q.front();
    q.pop();

    for(int node: adj_list[top]) {
      if(!visited[node]) {
        if(color[top] == black) {
          color[node] = red;
          lyk++;
        } else {
          color[node] = black;
          vamp++;
        }

        visited[node] = 1;
        q.push(node);
      }
    }
  }

}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  int tc = 1;

  while(T--) {
    memset(adj_list, 0, sizeof(adj_list));
    int n, u, v, ans = 0, mx = INT_MIN;
    cin >> n;
    while(n--) {
      cin >> u >> v;
      adj_list[u].push_back(v);
      adj_list[v].push_back(u);
      mx = max({mx, u, v});
    }
    memset(color, 0, sizeof(color));
    memset(visited, 0, sizeof(visited));

    for (int i = 1; i <= mx; i++) {
      vamp = lyk = 0;
      if(color[i] == 0 && !adj_list[i].empty()) {
        bfs(i);
      }
      ans += max(vamp, lyk);
    }
    cout << "Case " << tc++ << ": " << ans << nl;
  }

  return 0;
}