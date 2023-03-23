#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int visited[N];
int level[N];

vector<int> adj_list[N];

void bfs(int src){
  queue<int> q;
  q.push(src);
  visited[src] = 1;

  while(!q.empty()){
    int head = q.front();
    q.pop();

    for(int adj_node: adj_list[head]){
      if(!visited[adj_node]){
        visited[adj_node] = 1;
        level[adj_node] = level[head] + 1; // level of adj_node is level of head + 1
        q.push(adj_node);
      }
    }
  }
}

int main(){
  int nodes, edges;
  cin>>nodes>>edges;

  for(int i=0; i<edges; i++) {
    int u, v;
    cin>>u>>v;
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
  }

  int src = 0;
  bfs(src);

  for(int i=0; i<nodes; i++){
    cout<<"Node "<<i<<" is at level "<<level[i]<<"\n";
  }
  return 0;
}



/*
(0)  (1)  (2) (3)
0----1----2----3
     |    |
     |    |
     5----4
    (2)  (3)
6 6

0 1
2 3
1 5
2 4
5 4
1 2

6 7
0 1
0 3
0 4
1 2
1 5
5 4
4 2

*/
