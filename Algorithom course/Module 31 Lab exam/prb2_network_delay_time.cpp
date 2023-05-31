// https://leetcode.com/problems/network-delay-time/

#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
const int N = 6005;

vector<pair<int, int>> adj_list[N];
int dist[N], visited[N];

class Solution {
public:
    int dijkstra(int src, int dst) {
      for (int i = 1; i <= dst; i++) {
        dist[i] = INF;
      }

      dist[src] = 0;
      priority_queue<pair<int, int>> pq;
      pq.push({0, src});
      while(!pq.empty()) {
        pair<int, int> head = pq.top();
        pq.pop();

        int s_node = head.second;
        if(visited[s_node]) continue;
        visited[s_node] = 1;  

        for(auto child_node: adj_list[s_node]) {
          int nxt_node = child_node.first;
          int edge_cost = child_node.second;
          int distance = dist[s_node] + edge_cost;

          if(distance < dist[nxt_node]) {
            dist[nxt_node] = distance;
            pq.push({-dist[nxt_node], nxt_node});
          }
        }
      }

      int ans = 0;
      for (int i = 1; i <= dst; i++) {
        if(dist[i] == INF)
          return -1;
        ans = max(ans, dist[i]);
      }
      return ans;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      
      for (int i = 0; i < times.size(); i++) {
        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];
        adj_list[u].push_back({v, w});
      }

      int ans = dijkstra(k, n);

      return ans;
    };
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
  int n = 4, k = 2;

  // vector<vector<int>> times = {{1,2,1}};
  // int n = 2, k = 2;

  // vector<vector<int>> times = {{1, 2, 1}, {2, 1, 3}};
  // int n = 2, k = 2;

  Solution s;
  cout<< s.networkDelayTime(times, n, k) << "\n";
  return 0;
}