// MAX FLOW

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1e6+6;
int n, m;
int s, t;
int parent[MAX]; // parent[u] = v -> v la cha cua u 
int f[MAX][MAX];
int c[MAX][MAX];
vector <int> A[MAX];
int ans;

void input() {
  cin >> n >> m;
  cin >> s >> t;

  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) c[i][j] = 0;
  }

  for(int i = 1; i <= m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;

    c[u][v] = w;
    A[u].push_back(v);
  }
}

int main() {

  //input();
  return 0;
}