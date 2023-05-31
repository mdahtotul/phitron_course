// https://leetcode.com/problems/network-delay-time/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  struct Node {
    int node, cost;
  };
  struct qNode {
    int node, dist;
  };
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    unordered_map<int, vector<Node *>> adj_list;
    for (int i = 0; i < times.size(); i++)
    {
      Node *newNode = new Node;
      int u = times[i][0];
      newNode->node = times[i][1];
      newNode->cost = times[i][2];
      adj_list[u].push_back(newNode);
      }

      qNode *qn = new qNode;
      qn->node = k;
      qn->dist = 0;
      queue<qNode *> q;
      q.push(qn);

      vector<int> dist(n + 1, INT_MAX);
      dist[k] = 0;
      int time = 0;

      while(!q.empty()) {
        qNode *head = q.front();
        q.pop();

        for (auto node : adj_list[head->node]) {
          if (dist[node->node] > dist[head->node] + node->cost) {
            dist[node->node] = dist[head->node] + node->cost;
            qNode *newNode = new qNode;
            newNode->node = node->node;
            newNode->dist = dist[node->node];
            q.push(newNode);
          }
        }
      }

      for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) return -1;
        time = max(time, dist[i]);
      }
      return time;
    };
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  // vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
  // int n = 4, k = 2;

  // vector<vector<int>> times = {{1,2,1}};
  // int n = 2, k = 1;
  // int n = 2, k = 2;

  vector<vector<int>> times = {{1, 2, 1}, {2, 1, 3}};
  int n = 2, k = 2;

  Solution s;
  cout<< s.networkDelayTime(times, n, k) << "\n";
  return 0;
}