// Connected Components of undirected graphs
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int MAXN = 1e5 + 5;

vector<int> adj[MAXN];
bool visited[MAXN];

void dfs(int u) {
    visited[u] = true;
    for (int v = 0; v < adj[u].size(); ++v) {
    //for(int v : adj[u]) {
        if(!visited[adj[u][v]]) {
            dfs(adj[u][v]);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        //adj[v].push_back(u);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            cnt++;
            dfs(i);
        }
    }
    cout << cnt << endl;
    return 0;
}